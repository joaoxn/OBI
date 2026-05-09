#include <bits/stdc++.h>
#include <filesystem>
#include <chrono>
namespace fs = std::filesystem;
using namespace std;


string compiledProgram = "obijudge_compiledprogram.exe";
const string PROGRAM_OUTPUT = "obijudge_programout.txt";
int TIME_LIMIT = 1000;

fs::path programa;
fs::path pastaTestes;

set<string> availableLangs = {".cpp", ".java"};
string programaLang;

int scanPrograma() {
    printf("Digite o tempo limite (ms), ou 0 para nao verificar TLE.\nPara usar o padrao (1000ms), escreva o caminho para o programa: ");

    string s;
    getline(cin, s);
    char* p;
    long converted = strtol(s.c_str(), &p, 10);
    
    if (p == s.c_str()) {
        programa = s;
    } else {
        if (converted == 0) converted = INT_MAX;
        else if (converted < 20) converted *= 1000;
        TIME_LIMIT = converted;

        printf("Escreva o caminho para o programa: ");
        string temp;
        getline(cin, temp);
        programa = temp;
    }

    programaLang = programa.extension().string();
    if (!availableLangs.count(programaLang)) {
        printf("Linguagem \"%s\" não reconhecida ou indisponível.\n", programaLang.c_str());
        return -1;
    }
    return 0;
}

void procurarTestes() {
    pastaTestes = programa;
    string nomePrograma = pastaTestes.stem().string();
    bool found = false;
    for (const auto& entrada : fs::directory_iterator(pastaTestes.parent_path())) {
        if (!entrada.is_directory()) continue;
        string nomePasta = entrada.path().filename().string();
        
        if (nomePrograma.size() > 0 && nomePasta.size() >= nomePrograma.size() 
        && nomePrograma == nomePasta.substr(nomePasta.size()-nomePrograma.size())) {
            pastaTestes = entrada.path();
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Escreva o caminho para a pasta de testes: ");
        string temp;
        getline(cin, temp);
        pastaTestes = temp;
    }
}

void test() {
    int totalSolved = 0;
    int totalTests = 0;
    for (const auto& subtarefa : fs::directory_iterator(pastaTestes)) {
        string subtarefaNome = subtarefa.path().stem().string();
        int solvedAmt = 0;
        int testsAmt = 0;
        
        for (const auto& testeEntry : fs::directory_iterator(subtarefa)) {
            fs::path input = testeEntry.path();
            if (input.extension() != ".in") continue;
            string testeNome = input.stem().string();
            
            ++testsAmt;

            fs::path solOutput = input;
            solOutput.replace_extension(".sol");
            
            string comandoExec = compiledProgram+" < \""+ input.string() +"\" > "+PROGRAM_OUTPUT;
            if (programaLang == ".java")
                comandoExec = "java "+ comandoExec;

            auto start = chrono::high_resolution_clock::now();
            int execution_status = system(comandoExec.c_str());
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            int executionMilliseconds = duration.count();

            string comandoDiff = "fc /W "+PROGRAM_OUTPUT+" \""+ solOutput.string() +"\" > nul";
            int resultado = system(comandoDiff.c_str());

            string status;
            if (execution_status != 0) status = "Runtime Error";
            if (resultado != 0) status = "Wrong Answer";
            else if (executionMilliseconds > TIME_LIMIT) status = "Time Limit Exceeded";
            else status = "Accepted";

            printf("Subtarefa %s - Teste %s: %s (%dms)\n", 
                subtarefaNome.c_str(), testeNome.c_str(), status.c_str(), duration.count());
            
            if (status == "Accepted") ++solvedAmt;
        }
        totalSolved += solvedAmt;
        totalTests += testsAmt;
        printf("Subtarefa %s: %d/%d Aceitos (%.2f%)\n\n", subtarefaNome.c_str(), solvedAmt, testsAmt, (100.0 * solvedAmt/testsAmt));
    }
    printf("Total: %d/%d Aceitos (%.2f%)", totalSolved, totalTests, (100.0*totalSolved/totalTests));
}

int compilar() {
    int compilacao = -1;
    if (programaLang == "cpp") {
        compilacao = system(("g++ \""+programa.string()+"\" -o "+compiledProgram).c_str());
    } else if (programaLang == ".java") {
        compilacao = system(("javac \""+ programa.string() +"\" -d .").c_str());
        compiledProgram = programa.stem().string();
    }
    if (compilacao != 0) {
        printf("Compiler Error\n");
        return -1;
    }
    return 0;
}

void clearFolder() {
    fs::path dir = "./";
    set<string> permaFiles = {"obi-judge.cpp", "obi-judge.exe"};

    for (const auto& file : fs::directory_iterator(dir)) {
        if (permaFiles.count(file.path().filename().string())) 
            continue;
        fs::remove(file.path());
    }
}

int main() {
    if (scanPrograma() == -1) return 0;
    
    if (compilar() == -1) return 0;
    
    procurarTestes();

    test();
    
    clearFolder();

    return 0;
}
