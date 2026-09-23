// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //printf(args)
#define debugln(args...) debug(args); debug("\n")
typedef long long ll;

int n, m;
vector<vector<int>> mt;
vector<vector<int>> pref;

vector<vector<int>> dp;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    mt.resize(n,vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }

    dp.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        int start = 0;
        for (int j = 1; j <= m; j++) {
            if (j == m || mt[i][j-1] >= mt[i][j]) {
                for (int k = start; k < j; k++) dp[i][k] = j-1;
                start = j;
            }
        }
    }

    int maxv = 1;

    for (int l = 0; l < n; l++) {
        for (int c = 0; c < m; c++) {
            for (int i0 = 0; i0 < n-l; i0++) {
                for (int j0 = 0; j0 < m-c; j0++) {
                    // retangulo:
                    // linhas [i0,i0+l] cols [j0,j0+c]

                    bool outCrescent = true;
                    for (int i = i0; i <= i0+l; i++) {
                        
                        // bool crescent = true;
                        // for (int j = j0+1; j <= j0+c; j++) {
                        //     if (mt[i][j-1] < mt[i][j]) continue;
                        //     crescent = false;
                        //     break;
                        // }
                        if (i0==0 && i0+l==1 && j0==1 && j0+c==2) debug("%d %d = %d ", j0+c, dp[i][j0], j0+c > dp[i][j0]);
                        if (j0+c > dp[i][j0]) {
                            outCrescent = false;
                            break;
                        }
                    }
                    if (outCrescent)
                        for (int i = i0+1; i <= i0+l; i++) {
                            if (mt[i-1][j0+c] < mt[i][j0]) continue;
                            if (i0==0 && i0+l==1 && j0==1 && j0+c==2) debug("%d ", i);
                            outCrescent = false;
                            break;
                        }
                    
                    debugln("[%d,%d] [%d,%d] (%d): %d", i0,i0+l, j0,j0+c, (l+1)*(c+1), outCrescent);
                    if (outCrescent) maxv = max(maxv, (l+1)*(c+1));
                }
            }
        }
    }

    cout << maxv << "\n\n";

    return 0;
}