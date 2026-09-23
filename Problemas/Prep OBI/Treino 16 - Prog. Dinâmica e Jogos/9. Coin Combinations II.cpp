// https://cses.fi/problemset/task/1636
// TLE

#include <bits/stdc++.h>
using namespace std;

#define IGN if (0)
#define INF INT_MAX;
typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 1e9+7;
int n, x;
vector<int> c;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    c.resize(n);
    dp.resize(x+1, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(),c.end());
    
    for (int i = 0; i < n; i++) dp[0][i] = 1;

    for (int i = 1; i <= x; i++) {
        for (int j = n-1; j >= 0; j--) {
            int sum = 0;
            for (int k = j; k < n; k++) {
                int v = c[k];
                if (i >= v)
                    sum = (sum + dp[i-v][k]) % MOD;
            }
            dp[i][j] = sum;

        }
    }

    cout << dp[x][0] << '\n';
    // for (int i = 0; i <= x; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

/*

SRTBOT
Subproblems:
dp[i][j] = count(i)
i: desired sum
j: index of value of origin (last value used)

Relate:
dp[i][j] = sum(dp[i-e][idx(e)] for e in c if e >= c[j])

Topo: for i=[1..x]: for j=[n-1..0]: dp[i][j]
Base: dp[0] = 1
Origin: dp[x]
Time Complexity: O(x*n) * O(n) = O(n²*x) = 10^10
*/