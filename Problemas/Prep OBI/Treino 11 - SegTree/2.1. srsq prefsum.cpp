#include <bits/stdc++.h>
using namespace std;

#define debug(args...) do{ printf(args); fflush(stdout); }while(0)
#define debugln(args...) do{ debug(args); debug("\n"); }while(0)
#define debuglist(list, out) do{ for(auto&x:list) debug(out,x); }while(0)
typedef long long ll;

ll n, q;
vector<ll> v;
vector<ll> prefsum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> q;
    v.resize(n);
    prefsum.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        prefsum.push_back(v[i]+prefsum[i]);
    }
    n = v.size();

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << (prefsum[r]-prefsum[l-1]) << '\n';
    }
}