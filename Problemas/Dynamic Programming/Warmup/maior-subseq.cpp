#include <bits/stdc++.h>
using namespace std;

int n;
int v[10000];
int dp[10000];

int main() {
    for (n = 0; scanf("%d", v+n); n++) {}
    
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] <= v[i] && dp[j] > max) max = dp[j];
        }
        dp[i] = max+1;
    }
    int max = 1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > max) max = dp[i];
    }
    printf("%d\n", max);

    return 0;
}