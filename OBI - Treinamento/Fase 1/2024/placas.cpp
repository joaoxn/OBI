#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    
    int type = 0;

    if (s.size() == 8 && s[3] == '-') {
        bool is1 = true;
        for (int i = 0; i < 3; i++) {
            char c = s[i];
            if (c < 'A' || c > 'Z') {
                is1 = false;
                break;
            }
        }
        for (int i = 4; i < 8; i++) {
            char c = s[i];
            if (c < '0' || c > '9') {
                is1 = false;
            }
        }
        if (is1) type = 1;
    } else if (s.size() == 7) {
        bool is2 = true;
        for (int i : {0,1,2,4}) {
            char c = s[i];
            if (c < 'A' || c > 'Z') {
                is2 = false;
            }
        }
        for (int i : {3,5,6}) {
            char c = s[i];
            if (c < '0' || c > '9') {
                is2 = false;
            }
        }
        if (is2) type = 2;
    }

    cout << type << "\n";

    return 0;
}