#include <bits/stdc++.h>
using namespace std;

int n, c;
int w[1000], v[1000];
int dp[1000][1000];

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", w+i, v+i);
    }

    for (int i = 0; i < n; i++) {
        for (int cap = 0; cap <= c; cap++) {
            if (i == 0) {
                dp[i][cap] = cap >= w[i] ? v[i] : 0;
                continue;
            }

            if (cap < w[i]) {
                dp[i][cap] = dp[i-1][cap];
                continue;
            }

            dp[i][cap] = max(dp[i-1][cap], dp[i-1][cap-w[i]] + v[i]);
        }
    }

    printf("%d\n", dp[n-1][c]);
    return 0;
}