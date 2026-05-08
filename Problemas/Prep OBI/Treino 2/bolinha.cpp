//
// Created by xnaxg on 07/04/2026.
//

#include <bits/stdc++.h>
using namespace std;

int n, i, j;
int m[101][101];
bool flag[101][101];
int flags = 0;

void solve(int i, int j) {
    flag[i][j] = true;
    ++flags;
    array<pair<int,int>,4> map = {
        pair(0,1),pair(-1,0),pair(0,-1),pair(1,0)
    };

    for (int k = 0; k < 4; k++) {
        int x = i + map[k].first;
        int y = j + map[k].second;
        if (x < 0 || x >= n || y < 0 || y >= n || flag[x][y] || m[x][y] < m[i][j]) continue;
        solve(x,y);
    }
}

int main() {
    cin >> n >> i >> j;
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < n; q++) {
            cin >> m[p][q];
        }
    }
    --i;--j;
    solve(i,j);
    cout << flags << "\n";
}
