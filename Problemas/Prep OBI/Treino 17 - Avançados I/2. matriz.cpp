// https://olimpiada.ic.unicamp.br/pratique/pu/2019/f2/matriz/
// OBI 2019 Fase 2 Nível Sênior
// 

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define fi first
#define se second
typedef pair<int,int> pii;

int n, m;
vector<vector<int>> mt;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    mt.resize(n,vector<int>(m));
    dp.resize(n,vector<int>(m));
    prefcol.resize(n,vector<int>(m));
    preflin.resize(n,vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mt[i][j];
            if (i > 0)
                prefcol[i][j] = min(mt[i][j],prefcol[i-1][j]);
            else prefcol[i][j] = mt[i][j];
            if (j > 0)
                preflin[i][j] = min(mt[i][j],prefcol[i][j-1]);
            else preflin[i][j] = mt[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (j == 1 || i == 1) {
                dp[j]
            }


        }
    }

    return 0;
}