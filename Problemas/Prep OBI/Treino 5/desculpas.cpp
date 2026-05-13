#include <bits/stdc++.h>
using namespace std;

int cap, f;

int main() {
    for (int t = 1; scanf("%d %d", &cap, &f) > 0 && (cap!=0 || f!=0); ++t) {
        int c[f];
        int v[f];
        int dp[cap+1][f];
        memset(c, 0, sizeof c);
        memset(v, 0, sizeof v);
        memset(dp, 0, sizeof dp);
        
        for (int i = 0; i < f; ++i) {
            scanf("%d %d", c+i, v+i);
        }

        for (int i = c[0]; i <= cap; i++) {
            dp[i][0] = v[0];
        }

        for (int j = 1; j < f; j++) {
            for (int i = 0; i <= cap; i++) {
                if (i >= c[j])
                    dp[i][j] = max(dp[i][j-1], dp[i-c[j]][j-1]+v[j]);
                else dp[i][j] = dp[i][j-1];
            }
        }
        printf("Teste %d\n%d\n\n", t, dp[cap][f-1]);
    }

    return 0;
}

/* Mochila
dp[i][c] = max(dp[i-1][c],dp[i-1][c-w[i]]+v[i])

dp[w] = max(dp[w],dp[w-peso]+valores[i])
*/