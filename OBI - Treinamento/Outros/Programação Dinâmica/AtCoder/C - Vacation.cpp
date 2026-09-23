// https://vjudge.net/problem/AtCoder-dp_c
// https://vjudge.net/contest/807537#problem/C

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second.first
#define th second.second
typedef pair<int,pair<int,int>> trio;

int n;
vector<vector<int>> v;
vector<vector<int>> dp;

int main() {
    cin >> n;
    v.resize(n, vector<int>(3));
    dp.resize(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    dp[0] = v[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + v[i][0];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + v[i][1];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + v[i][2];
    }

    cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}