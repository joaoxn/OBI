// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << ": " << (x) << "\n"
#define debugf(args...) cout <<  format(args)
#define fi first
#define se second
#define ll long long
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define MOD 1000000007

// #define int long long

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

    cout << format("{}", n);

    return 0;
}
