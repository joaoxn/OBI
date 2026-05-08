//
// Created by xnaxg on 31/03/2026.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string m_in, n_in;
vector<string> prev_m, prev_n;

int remainder(const string& m, const string& n) {
    const int d = stoi(n,nullptr,2);

    int curr = 0;
    for (char c : m) {
        int bit = c == '1';
        curr = (curr*2+bit)%d;
    }
    return curr;
}

string solve() {
    int p = prev_m.size()-1 + prev_n.size()-1;
    int limitBmask = (1 << p);

    for (int bmask = 0; bmask < limitBmask; bmask++) {
        string m, n;
        for (int j = 0; j < prev_m.size()-1; j++) {
            m += prev_m[j];
            m += bmask & (1<<j) ? "1" : "0";
        }
        m += prev_m.back();
        for (int j = prev_m.size()-1; j < p; j++) {
            n += prev_n[j-prev_m.size()+1];
            n += bmask & (1<<j) ? "1" : "0";
        }
        n += prev_n.back();

        if (remainder(m,n)==0)
            return m;
    }
    return "";
}

int main() {
    cin >> m_in >> n_in;

    string s;

    stringstream ssm(m_in);
    while (getline(ssm, s, '*')) {
        prev_m.push_back(s);
    }
    if (m_in.back() == '*') prev_m.emplace_back("");

    if (n_in.front() == '*') prev_n.emplace_back("");
    stringstream ssn(n_in);
    while (getline(ssn, s, '*')) {
        prev_n.push_back(s);
    }
    if (n_in.back() == '*') prev_n.emplace_back("");

    cout << solve();
}

/*
111*
1*
-> 1110
101**
11
-> 10101
*1**
100
-> 100
1001001001**00100*100100100100010010010001*001001001001001**0010010010001**
1*00**100*01*1

*/