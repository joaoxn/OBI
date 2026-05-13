#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    for (int t = 1; cin >> s; ++t) {
        int scopes = 0;
        for (char c : s) {
            if (c == '(') {
                ++scopes;
            }
            else if (c == ')') {
                --scopes;
                if (scopes < 0) break;
            }
        }
        printf(scopes == 0 ? "correct\n" : "incorrect\n");
    }

    return 0;
}
