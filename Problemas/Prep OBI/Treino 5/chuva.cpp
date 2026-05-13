#include <bits/stdc++.h>
using namespace std;

int n, m;
char ans[500][500];

void dfs(int i, int j) {
    ans[i][j] = 'o';
    if (i+1 < n && ans[i+1][j] == '.') {
        dfs(i+1,j);
    }
    if (i+1 < n && ans[i+1][j] == '#') {
        if (j-1 >= 0 && ans[i][j-1] == '.') dfs(i, j-1);
        if (j+1 < m && ans[i][j+1] == '.') dfs(i, j+1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    char mat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);
            ans[i][j] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 'o') {
                mat[i][j] = 0;
                dfs(i,j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
