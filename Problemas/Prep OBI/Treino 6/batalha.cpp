#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int mat[101][101];
pair<int,int> dirs[] = {{-1,0},{0,1},{1,0},{0,-1}};
bool vis[101][101];

bool dfs(int i, int j) {
    vis[i][j] = true;

    bool sunk = true;
    for (auto dir : dirs) {
        int newi = i + dir.first;
        int newj = j + dir.second;
        if (newi <= 0 || newi > n || newj <= 0 || newj > m) continue;
        if (vis[newi][newj]) continue;
        if (mat[newi][newj] == '.') continue;
        if (mat[newi][newj] == '#') sunk = false;
        if (!dfs(newi,newj)) sunk = false;
    }
    return sunk;
}

int main() {
    scanf("%d %d ", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%c", &mat[i][j]);
        }
        scanf(" ");
    }
    scanf("%d", &k);
    vector<int> ls;
    vector<int> cs;
    for (int i = 0; i < k; ++i) {
        int l, c;
        scanf("%d %d", &l, &c);
        if (mat[l][c] == '#') {
            mat[l][c] = '*';
            ls.push_back(l);
            cs.push_back(c);
        }
    }
    int sunk = 0;
    for (int i = 0; i < ls.size(); ++i) {
        int l = ls[i];
        int c = cs[i];
        if (!vis[l][c]) {
            if (dfs(l,c)) {
                ++sunk;
            }
        }
    }

    printf("%d\n", sunk);

    return 0;
}
