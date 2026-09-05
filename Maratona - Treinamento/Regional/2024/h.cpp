#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

string m, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    int asts = 0;
    int mAsts = 0;
    for (int i = 0; i < m.size(); i++) if (m[i] == '*') mAsts++;
    for (int i = 0; i < n.size(); i++) if (n[i] == '*') asts++;
    asts += mAsts;

    int mask;
    for (mask = 0; mask < (1<<asts); mask++) {
        string m1 = m, n1 = n;
        int j = 0;
        for (int i = 0; i < m1.size(); i++) {
            if (m1[i] != '*') continue;
            m1[i] = '0' + (mask & (1<<j++) > 0);
        }
        for (int i = 0; i < n1.size(); i++) {
            if (m1[i] != '*') continue;
            n1[i] = '0' + (mask & (1<<j++) > 0);
        }
        if (stoi(m1,nullptr,2)%stoi(n1,nullptr,2) == 0) {
            cout << m1;
            return 0;
        }
    }

    return 0;
}