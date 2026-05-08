#include <bits/stdc++.h>
using namespace std;

int n, x;
int c[100];
int dp[1000001];
const int mod = 1e9+7;

int main() {
    scanf("%d %d", &n, &x);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    sort(c,c+n);

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int v = 1; v <= x; v++) {
            if (c[i] > v) continue;
            dp[v] += dp[v-c[i]];
            dp[v] %= mod;
        }
    }

    printf("%d\n", dp[x] % mod);

    return 0;
}