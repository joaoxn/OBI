#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
typedef long long ll;

ll n, amt=0;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n+1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i > 0 && v[i-1] > v[i]) {
            amt += v[i-1]-v[i];
            v[i] = v[i-1];
        }
    }

    cout << amt;

    return 0;
}