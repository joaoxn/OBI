//
// Created by xnaxg on 07/04/2026.
//

#include <bits/stdc++.h>
using namespace std;

bool compare(const string& a, const string& b) {
    return a.size() > b.size();
}

int main() {
    int n;
    cin >> n;
    string _;
    getline(cin, _);

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        stable_sort(words.begin(), words.end(), compare);
        cout << words[0];
        for (int j = 1; j < words.size(); j++) {
            cout << " " << words[j];
        }
        cout << "\n";
    }
}
/*
3
Ctuisebbbxghuxmtxqocfzaymvylzyjqmfxtxdty kkgobylhzmqgpnbefletaiyqyqxjfabwykqlwb...
Mhdojhvocwoubnbyqksbyqnptebfzchllbzmcztu llinpfesmlzevbbvcmmzpgctscqtpsgvdnwrzr...
bqtetewnohyfteoyetricuiqibapugpndadjo tdigmplkryprdfvwrsiczkkoyuuatgudpscgd Emb...

4
Top Coder comp Wedn at midnight
one three five
I love Cpp
sj a sa df r e w f d s a v c x z sd fd

*/