// https://atcoder.jp/contests/dp/tasks/dp_n

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX;
int n;
vector<ll> v;
vector<vector<ll>> dp;
vector<vector<ll>> cost;

int main() {
    cin >> n;
    v.resize(n);
    dp.resize(n, vector<ll>(n));
    cost.resize(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) dp[i][i] = v[i];

    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n-l; i++) {
            int j = i+l;
            dp[i][j] = INF;
            cost[i][j] = INF;
            for (int k = i; k < j; k++) {
                ll take = dp[i][k]+dp[k+1][j];
                ll costTake = cost[i][k]+cost[k+1][j]+take;
                // eh guloso? pois se botar take < dp[i][j] dá WA
                // take <= dp[i][j] sempre é verdadeiro quando costTake é menor que o custo atual
                if (costTake < cost[i][j] && take <= dp[i][j]) {
                    dp[i][j] = take;
                    cost[i][j] = costTake;
                }
            }
        }
    }

    cout << cost[0][n-1] << '\n';
}