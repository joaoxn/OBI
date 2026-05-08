#include <bits/stdc++.h>
using namespace std;

int t, n;
int c[100000];
int dp[100000];

int main() {
    scanf("%d", &t);
    for (n = 0; scanf("%d", c+n) && c[n] != 0; n++) {}

    dp[0] = 0;

    for (int i = 1; i <= t; i++) {
        int min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (c[j] > i || dp[i-c[j]] == INT_MAX) continue;
            int val = dp[i-c[j]] + 1;
            if (val < min) min = val;
        }
        dp[i] = min;
    }

    printf("%d\n", dp[t]);

    return 0;
}