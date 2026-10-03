#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define int long long

int n, w;
vector<int> p;
vector<int> v;
vector<vector<int>> dp;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;
    p.resize(n);
    v.resize(n);
    dp.resize(n,vector<int>(w+1));

    for (int i = 0; i < n; i++) {
        cin >> p[i] >> v[i];
    }

    for (int c = p[0]; c <= w; c++) dp[0][c] = v[0];

    for (int i = 1; i < n; i++) {
        for (int c = 0; c <= w; c++) {
            if (c-p[i] < 0) dp[i][c] = dp[i-1][c];
            else dp[i][c] = max(dp[i-1][c],dp[i-1][c-p[i]]+v[i]);
        }
    }

    cout << dp[n-1][w];

    return 0;
}

/*

*/