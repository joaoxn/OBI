#include <bits/stdc++.h>
using namespace std;

char s[1000];
int dp[1000][1000];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n-len; i++) {
            int j = i+len-1;
            if (len == 1) {
                dp[i][j] = 1;
                continue;
            }

            if (len > 2 && s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
                continue;
            }

            dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
        }
    }

    printf("%d\n", dp[0][n-1]);

    return 0;
}

/*

if (ci == cj)
dp[i+1][j-1]+2
else
max(dp[i][j-1],dp[i+1][j])

*/