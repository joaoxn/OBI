// https://neps.academy/br/exercise/3573
// 100/100
// Iniciado: Sun Sep 27 09:52:59 2026
// Finalizado: Sun Sep 27 10:16:05 2026

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
typedef long long ll;

int n;
vector<ll> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.push_back(0);
    for (int i = 1; i <= n; i++) {
        bool x; cin >> x;
        if (x) a.push_back(i);
    }
    a.push_back(n+1);
    ll amt = 0;
    for (int i = 1; i < a.size()-1; i++) {
        amt += (a[i]-a[i-1])*(a[i+1]-a[i]);
    }

    cout << amt << '\n';
    // for (int i : a) cout << i << ' ';

    return 0;
}