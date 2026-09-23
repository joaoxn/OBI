// https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;

#define IGN if (0)
#define INF INT_MAX;
typedef long long ll;
typedef pair<int,int> pii;

const int MOD = 1e9+7;
int n, x;
vector<int> c;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    c.resize(n);
    dp.resize(x+1);
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        int sum = 0;
        for (int v : c) {
            if (i >= v)
                sum = (sum + dp[i-v]) % MOD;
        }
        dp[i] = sum;
    }

    cout << dp[x];
}

/*

SRTBOT
Subproblems:
dp[i] = count(i)

Relate:
dp[i] = sum(dp[i-v] for v in c)

Topo: for i=[1..x]
Base: dp[0] = 1
Origin: dp[x]
Time Complexity: O(x) * O(n) = O(n*x) = 10^8
*/