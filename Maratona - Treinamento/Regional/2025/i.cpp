#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define debug(args...) //printf(args)
// #define dist(i,j) (max(abs(p[i].ff-p[j].ff),abs(p[i].ss-p[j].ss)))

typedef long long ll;

int n;
vector<pair<ll,ll>> p;
vector<ll> dist;

bool f(ll r1) {
    ll r = r1;
    for (int i = 0; i < n-1; i++) {
        ll distance = dist[i];
        debug("dist(%d,%d)=%d\n", i,i+1,distance);
        if (r >= distance) return false;
        r = distance-r;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    p.resize(n);
    dist.resize(n-1);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        p[i] = {x,y};
        debug("p[%d]={%d,%d}\n", i, p[i].ff, p[i].ss);

        if (i > 0) dist[i-1] = (max(abs(p[i].ff-p[i-1].ff),abs(p[i].ss-p[i-1].ss)));
    }

    debug("f(%d)=%d\n", 3, f(3));

    ll l = 1, r = dist[0]-1;
    ll mid;
    ll res = -1;
    while (l <= r) {
        mid = (l+r)>>1;
        if (f(mid)) {
            res = mid;
            l = mid+1;
        } else r = mid-1;
    }
    while (1 < res && res < dist[0]-1 
        && f(res)) res++;
    
    while (1 < res && !f(res)) res--;

    cout << res << "\n";

    return 0;
}

