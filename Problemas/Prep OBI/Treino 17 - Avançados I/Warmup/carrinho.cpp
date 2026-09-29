// https://olimpiada.ic.unicamp.br/pratique/ps/2017/f3/carrinho/
// 100/100

#include <bits/stdc++.h>
using namespace std;

#define IGN if (0) 
#define debug(args...) printf(args)
#define fi first
#define se second
typedef pair<double,double> pii;

const double INF = DBL_MAX;
int n;
double total;
vector<pii> v;
vector<double> dp;

double t(double d, double c) {
    return d*d/c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> total;
    dp.resize(n+1, INF);
    for (int i = 0; i < n; i++) {
        double p, c; cin >> p >> c;
        v.push_back({p,c});
    }
    v.push_back({total,-1});
    dp[n] = 0;

    dp[n-1] = t(total-v[n-1].fi, v[n-1].se);

    for (int i = n-1; i >= 0; i--) {
        IGN cout << i << ": ";
        for (int j = i+1; j <= n; j++) {
            double d = v[j].fi-v[i].fi;
            double c = v[i].se;
            IGN cout << t(d,c)+dp[j] << ' ';
            dp[i] = min(dp[i], t(d,c)+dp[j]);
        }
        IGN cout << '\n';
    }

    cout << fixed << setprecision(3) << dp[0] << '\n';

    IGN for (int i = 0; i < n; i++) {
        if (dp[i] < 100000)
        cout << dp[i] << ' ';
        else cout << "INF ";
    }

    return 0;
}