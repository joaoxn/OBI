#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;
int tempo[101];
int msg[101];
bool amigo[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int t = 1;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == 'T') {
            t += x-1;
            continue;
        }
        amigo[x] = true;
        if (c == 'R') {
            msg[x] = t;
        } else {
            tempo[x] += t-msg[x];
            msg[x] = 0;
        }
        t++;
    }
    for (int x = 1; x <= 100; x++) {
        if (!amigo[x]) continue;
        cout << x << " ";
        if (msg[x] != 0) {
            cout << -1;
        } else {
            cout << tempo[x];
        }
        cout << "\n";
    }

    return 0;
}