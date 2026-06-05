#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[51][51];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '1';
        }
    }

    for (int run = 0; run < q; run++) {
        int buffer[51][51];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int vivos = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0
                        || i+di < 0 || i+di >= n
                        || j+dj < 0 || j+dj >= n) continue;
                        vivos += a[i+di][j+dj];
                    }
                }
                if (a[i][j]) {
                    if (vivos == 2 || vivos == 3) buffer[i][j] = 1;
                    else buffer[i][j] = 0;
                } else {
                    if (vivos == 3) buffer[i][j] = 1;
                    else buffer[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = buffer[i][j];
            }
        }
    }
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}