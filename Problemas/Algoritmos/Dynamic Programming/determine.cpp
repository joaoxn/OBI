//
// Created by xnaxg on 21/04/2026.
//
#include <bits/stdc++.h>
using namespace std;

int n, a_n1;
int dp[30][30];

int a(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    if (i < j) {
        int max = 0;
        for (int k = i; k < j; k++) {
            int value = a(i,k) + a(k+1,j);
            if (value > max) {
                max = value;
            }
        }
        dp[i][j] = max;
        return max;
    }

    int result = 0;
    if (i < n) {
        int max = 0;
        for (int k = i+1; k <= n; k++)
            if (int value = a(k,1) + a(k,j); value > max)
                max = value;
        result += max;
    }
    if (j > 0) {
        int max = 0;
        for (int k = 1; k < j; k++)
            if (int value = a(i,k) + a(n,k); value > max)
                max = value;
        result += max;
    }
    dp[i][j] = result;
    return result;
}

int main() {
    while (cin >> n >> a_n1) {
        memset(dp, -1, sizeof dp);
        dp[n][1] = a_n1;
        printf("%d\n", a(1,n));
    }
}