#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, c, m;
int k[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c >> m;
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        k[x] = 1;
    }

    
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (k[x] == 0) continue;
        k[x] = 2;
    }
    int counts = 0;
    for (int i = 1; i <= n; i++) {
        if (k[i] == 1) {
            counts++;
        }
    }
    cout << counts << "\n";

    return 0;
}