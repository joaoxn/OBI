#include <bits/stdc++.h>
using namespace std;

char s[1000];
int dp[1000][1000];
int n;

int solve(int i, int j) {
    if (j-i == 0) return 1;
    if (dp[i][j] != 0) return dp[i][j];

    if (j-i > 1 && s[i] == s[j]) {
        dp[i][j] = solve(i+1,j-1) + 2;
        return dp[i][j];
    }

    dp[i][j] = max(solve(i,j-1), solve(i+1,j));
    return dp[i][j];
}

int main() {
    scanf("%s", s);
    n = strlen(s);

    printf("%d\n", solve(0, n-1));

    return 0;
}

/*

if (ci == cj)
dp[i+1][j-1]+2
else
max(dp[i][j-1],dp[i+1][j])

*/