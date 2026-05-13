#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[50][50];
pair<int,int> directions[] = {{-1,0},{0,1},{1,0},{0,-1}};

void solve(int i, int j) {
    for (pair<int,int> direction : directions) {
        int newi = i + direction.first;
        int newj = j + direction.second;
        if (newi >= n || newj >= m || newi < 0 || newj < 0) continue;
        if (mat[newi][newj] != 'A') continue;
        mat[newi][newj] = 'T';
        solve(newi,newj);
    }
}

int main() {
    for (int t = 1; scanf("%d %d", &n, &m) > 0 && (n!=0 || m!=0); ++t) {
        vector<pair<int,int>> ts;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &mat[i][j]);
                if (mat[i][j] == 'T') 
                    ts.push_back({i,j});
            }
        }

        for (pair<int,int> coord : ts) {
            solve(coord.first, coord.second);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%c",mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}