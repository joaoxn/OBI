// https://cses.fi/problemset/task/1652
// Accepted
// Prefix 2D

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, q;
vector<vector<char>> mt;
vector<vector<int>> pref;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    mt.resize(n,vector<char>(n));
    pref.resize(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mt[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) pref[i][j] += pref[i-1][j];
            if (j > 0) pref[i][j] += pref[i][j-1];
            if (i > 0 && j > 0)
                pref[i][j] -= pref[i-1][j-1];
            pref[i][j] += (int) (mt[i][j] == '*');
        }
    }

    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;

        int res = pref[y2][x2];
        if (x1 > 0) res -= pref[y2][x1-1];
        if (y1 > 0) res -= pref[y1-1][x2];
        if (x1 > 0 && y1 > 0) 
            res += pref[y1-1][x1-1];

        cout << res << '\n';
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << pref[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}