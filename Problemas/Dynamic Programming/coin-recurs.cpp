#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x;
int c[100];
int    dp[1000001];
bool flag[1000001];
const int mod = 1e9+7;

int solve(int value) {
    if (value == 0) return 1;
    if (flag[value]) return dp[value];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] > value) continue;
        int solutions = solve(value - c[i]);
        sum += solutions;
        sum %= mod;
    }
    flag[value] = true;
    dp[value] = sum;
    return sum;
}

int32_t main() {
    scanf("%d %d", &n, &x);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    printf("%d\n", solve(x) % mod);

    return 0;
}