#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> mt;
vector<vector<bool>> vis;

vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int i, int j) {
    if (vis[i][j] || mt[i][j] == '#')
        return;
    vis[i][j] = true;

    for (auto dir : dirs) {
        int ni = i + dir.first;
        int nj = j + dir.second;
        if (ni >= n || ni < 0)
            continue;
        if (nj >= m || nj < 0)
            continue;
        dfs(ni, nj);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    mt.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || mt[i][j] == '#')
                continue;
            counter++;
            dfs(i, j);
        }
    }
    cout << counter;
}