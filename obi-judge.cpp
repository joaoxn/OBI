#include <bits/stdc++.h>
#include <filesystem>
#include <chrono>
namespace fs = std::filesystem;
using namespace std;


const string COMPILED_PROGRAM = "obijudge_compiledprogram.exe";
const string PROGRAM_OUTPUT = "obijudge_programout.txt";
int TIME_LIMIT = 1000;

int main() {
    printf("Digite o tempo limite (ms), ou 0 para nao verificar TLE.\nPara usar o padrao (1000ms), escreva o caminho para o programa: ");

    string s, programa;
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
        getline(cin, programa);
    }

    int compilacao = system(("g++ \""+programa+"\" -o "+COMPILED_PROGRAM).c_str());
    if (compilacao != 0) {
        printf("Compiler Error\n");
        return -1;
    }
    
    fs::path pastaTestes = programa;
    string nomePrograma = pastaTestes.stem().string();
    bool found = false;
    for (const auto& entrada : fs::directory_iterator(pastaTestes.parent_path())) {
        if (!entrada.is_directory()) continue;
        string nomePasta = entrada.path().filename().string();
        
        if (nomePrograma.size() > 0 && nomePasta.size() >= nomePrograma.size() 
        && nomePrograma == nomePasta.substr(nomePasta.size()-nomePrograma.size(), nomePrograma.size())) {
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
            
            auto start = chrono::high_resolution_clock::now();
            int execution_status = system((COMPILED_PROGRAM+" < \""+ input.string() +"\" > "+PROGRAM_OUTPUT).c_str());
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

    if (fs::exists(COMPILED_PROGRAM)) {
        fs::remove(COMPILED_PROGRAM);
    }
    if (fs::exists(PROGRAM_OUTPUT)) {
        fs::remove(PROGRAM_OUTPUT);
    }

    return 0;
}
