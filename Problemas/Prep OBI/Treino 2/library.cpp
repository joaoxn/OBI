//
// Created by xnaxg on 07/04/2026.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        string s[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        sort(s,s+n);
        for (string str : s) {
            printf("%s\n", str.c_str());
        }
    }
}
