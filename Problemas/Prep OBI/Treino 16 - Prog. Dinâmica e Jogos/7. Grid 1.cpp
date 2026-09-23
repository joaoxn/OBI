// https://atcoder.jp/contests/dp/tasks/dp_h?lang=en

#include <bits/stdc++.h>
using namespace std;

#define IGN if (0)
#define INF LLONG_MAX
typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 1e9+7;
int n,m;
vector<vector<char>> mt;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    mt.resize(n,vector<char>(m));
    dp.resize(n+1,vector<int>(m+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }

    dp[n-1][m-1] = 1;

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (i==n-1 && j==m-1) continue;

            if (mt[i][j] == '#') dp[i][j] = 0;
            else dp[i][j] = (dp[i+1][j] + dp[i][j+1]) % MOD;
        }
    }

    cout << dp[0][0];
}

/*

SRTBOT
Subproblems:
dp[i][j] = count(i,j)

Relate:
if (mt[i][j] == '#'): dp[i][j] = 0
else: dp[i][j] = dp[i+1][j]+dp[i][j+1]

Topo: for i=[n-1,0]: for j=[m-1,0]
Base: dp[n-1][m-1] = 1
Origin: dp[0][0]
Time Complexity: O(n²)*O(1) = O(n²)
*/