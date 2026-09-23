// https://www.spoj.com/problems/ELIS/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> v;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        int maxv = 0;
        for (int j = i-1; j >= 0; j--) {
            if (v[j] >= v[i]) continue;
            if (dp[j] > maxv) maxv = dp[j];
        }
        dp[i] = maxv+1;
    }

    int maxv = 1;
    for (int i = 0; i < n; i++) {
        maxv = max(maxv,dp[i]);
    }
    cout << maxv;
}

/*

1 2 3 2 5
1 2 5
1 3 5
1 2 5
1 2 3 5

*/
