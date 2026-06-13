// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

#define debugcpp(x) cout << #x << ": " << (x) << "\n"
#define debug(args...) printf(args)
#define debugln(args...) debug(args);debug("\n")
#define fi first
#define se second
#define ll long long
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define MOD 1000000007
// #define int long long

ll modpow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res*base) % mod;
        base = (base*base) % mod;
        exp >>= 1;
    }
    return res;
}


int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed; // Floats do not print in scientific notation

    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }



    return 0;
}
