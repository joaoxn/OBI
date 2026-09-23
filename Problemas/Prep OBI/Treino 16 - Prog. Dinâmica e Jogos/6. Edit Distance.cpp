// https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>
using namespace std;

#define IGN if (0)
#define INF LLONG_MAX
typedef long long ll;
typedef pair<int,int> pii;

string s, t;
int n, m;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    n = s.size(); m = t.size();
    dp.resize(n+1, vector<int>(m+1));
    
    for (int i = n-1; i >= 0; i--) {
        dp[i][m] = 1+dp[i+1][m];
    }
    for (int j = m-1; j >= 0; j--) 
        dp[n][j] = 1+dp[n][j+1];

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            dp[i][j] = (int)(s[i]!=t[j]) + dp[i+1][j+1];
            dp[i][j] = min(dp[i][j], 1 + dp[i][j+1]);
            dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
        }
    }

    cout << dp[0][0] << "\n";

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j];
    //     }
    //     cout << '\n';
    // }
}

/*

SRTBOT
Subproblems:

Relate:

Topo: 
Base: 
Origin: 
Time Complexity: 
*/