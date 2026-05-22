// 100/100 - https://judge.beecrowd.com/pt/runs/code/49087441
#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
bool mat[201][201];

int main() {
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mat[a][b] = true;
    }
    
    int total = 0;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        if (mat[p.first][p.second]) continue;
        if (p.first <= 0 || n < p.first || p.second <= 0 || m < p.second) continue;
        total++;
        mat[p.first][p.second] = true;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i==0 && j==0) continue;
                q.push({p.first+i,p.second+j});
            }
        }
    }
    printf("%d\n", total);

    return 0;
}