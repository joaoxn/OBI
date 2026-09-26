// https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>
using namespace std;

#define IGN if (0)
#define INF INT_MAX;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
int n, x;
vector<int> c;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    c.resize(n);
    dp.resize(x + 1);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int w = c[i]; w <= x; w++) {
            dp[w] = (dp[w] + dp[w - c[i]]) % MOD;
        }
    }

    IGN for (int i = 0; i < x; i++) cout << dp[i] << ' ';
    cout << dp[x];
}

/*

SRTBOT
Subproblems:
dp[w] = count(w)

Relate:
dp[w] = sum(dp[w-v] for v in c)

Topo: for i=[1..n-1]: for w[c[i]..x]
Base: dp[0] = 1
Origin: dp[x]
Time Complexity: O(x) * O(n) = O(n*x) = 10^8
*/