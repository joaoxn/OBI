// https://vjudge.net/problem/AtCoder-dp_e
// https://vjudge.net/contest/807537#problem/E

#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX
typedef long long ll;

ll n, W, MAXV;
vector<ll> w;
vector<ll> v;
vector<vector<ll>> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> W;
    w.resize(n); v.resize(n);
    MAXV = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        MAXV += v[i];
    }
    dp.resize(n, vector<ll>(MAXV+1, INF));

    dp[0][0] = 0;
    dp[0][v[0]] = w[0];

    for (int i = 1; i < n; i++) {
        for (int val = 0; val < v[i]; val++) {
            dp[i][val] = dp[i-1][val];
        }
        for (int val = v[i]; val <= MAXV; val++) {
            if (dp[i-1][val-v[i]] == INF) 
                dp[i][val] = dp[i-1][val];
            else 
                dp[i][val] = min(dp[i-1][val],dp[i-1][val-v[i]]+w[i]);
        }
    }

    for (int j = MAXV; j >= 0; j--) {
        if (dp[n-1][j] <= W) {
            cout << j << '\n';
            break;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= MAXV; j++) {
    //         if (dp[i][j] > 100) cout << 'I' << ' ';
    //         else cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

/*

dp[i][w] = max(dp[i-1][w],dp[i-1][w-wi]+vi)

dp[i][v] = min(dp[i-1][v],dp[i-1][v-vi]+wi)

dp[0] = w=3,v=30
dp[1] = w=4,v=50; w=7,v=80
dp[2] = w=5,v=60; 

for (i = [0,n-1])
    for (w = [W,0])
        dp[w] = max(dp[w], dp[w-wi]+vi)

*/