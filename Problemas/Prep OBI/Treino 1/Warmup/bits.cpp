#include <bits/stdc++.h>
using namespace std;

int v;

int main() {
    for (int t = 1;; t++) {
        cin >> v;
        if (v == 0) break;
        int b[4];
        int p[] = {50,10,5,1};

        cout << "Teste "<< t << '\n';

        for (int i = 0; i < 4; i++) {
            b[i] = v/p[i];
            v %= p[i];
            cout << b[i] << (i < 3 ? " " : "");
        }
        cout << "\n\n";
    }
}