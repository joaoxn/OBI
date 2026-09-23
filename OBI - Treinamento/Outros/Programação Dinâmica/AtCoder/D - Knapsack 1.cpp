// https://vjudge.net/problem/AtCoder-dp_d
// https://vjudge.net/contest/807537#problem/D

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, c;
vector<ll> w;
vector<ll> v;
vector<vector<ll>> dp;

int main() {
    cin >> n >> c;
    w.resize(n);
    v.resize(n);
    dp.resize(n, vector<ll>(c+1));
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int k = 0; k <= c; k++)
        if (k >= w[0])
            dp[0][k] = v[0];
    
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < w[i]; k++) {
            dp[i][k] = dp[i-1][k];
        }
        for (int k = w[i]; k <= c; k++) {
            dp[i][k] = max(dp[i-1][k],dp[i-1][k-w[i]]+v[i]);
        }
    }
    cout << dp[n-1][c];
}

/*

f(i,c) = max(f(i-1,c-wi)+vi,f(i-1,c))

dp[0][c] = if (c >= wi) vi else 0

if (c >= wi)
    dp[i][c] = max(dp[i-1][c-wi]+vi,dp[i][c])


*/