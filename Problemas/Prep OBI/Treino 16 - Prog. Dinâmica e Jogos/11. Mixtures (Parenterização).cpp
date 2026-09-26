// https://www.spoj.com/problems/MIXTURES/en/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 100;
int n;
vector<int> v;
vector<vector<int>> dp;
vector<vector<int>> val;

int main() {
    while (cin >> n) {
        v.resize(n);
        dp.clear(); dp.resize(n,vector<int>(n));
        val.clear(); val.resize(n,vector<int>(n));

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        for (int i = 0; i < n; i++) val[i][i] = v[i];

        for (int l = 1; l < n; l++) {
            for (int i = 0; i < n-l; i++) {
                int j = i+l;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int vi = (val[i][k] + val[k+1][j])%MOD;
                    int smoke = val[i][k] * val[k+1][j];
                    int total = smoke + dp[i][k] + dp[k+1][j];
                    if (total < dp[i][j]) {
                        dp[i][j] = total;
                        val[i][j] = vi;
                    }
                }
            }
        }

        cout << dp[0][n-1] << '\n';
    }
}