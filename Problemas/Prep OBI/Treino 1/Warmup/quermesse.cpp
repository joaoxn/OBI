#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int t = 1;; t++) {
        cin >> n;
        if (n == 0) break;

        cout << "Teste " << t << '\n';

        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x == i) cout << x << "\n\n";
        }
    }
}