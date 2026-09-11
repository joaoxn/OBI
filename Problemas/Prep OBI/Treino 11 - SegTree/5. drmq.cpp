#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //do{ printf(args); fflush(stdout); }while(0)
#define debugln(args...) do{ debug(args); debug("\n"); }while(0)
typedef long long ll;

ll n, q, POWN;
vector<ll> v;

vector<ll> seg;

ll NEUTR = LLONG_MAX;
ll op(ll a, ll b) {
    return min(a,b);
}

void build(ll l, ll r, ll i=1, ll sl=0, ll sr=POWN-1) {
    if (sr < l || sl > r) return;
    if (sl == sr) {
        debugln("i,sl,sr=(%d,%d,%d)",i,sl,sr);
        seg[i] = v[sl];
        return;
    }

    ll mid = (sl+sr)>>1;
    build(l,r, i*2, sl, mid);
    build(l,r, i*2+1, mid+1, sr);
    seg[i] = op(seg[i*2],seg[i*2+1]);
}

void update(ll l, ll r, function<ll(ll)> upd, ll i=1, ll sl=0, ll sr=POWN-1) {
    if (sr < l || sl > r) return;
    if (sl == sr) {
        seg[i] = upd(seg[i]);
        return;
    }

    ll mid = (sl+sr)>>1;
    update(l,r,upd, i*2, sl, mid);
    update(l,r,upd, i*2+1, mid+1, sr);
    seg[i] = op(seg[i*2],seg[i*2+1]);
}

ll query(ll l, ll r, ll i=1, ll sl=0, ll sr=POWN-1) {
    if (sr < l || sl > r) return NEUTR;
    if (l <= sl && sr <= r) return seg[i];

    ll mid = (sl+sr)>>1;
    ll a = query(l,r, i*2, sl, mid);
    ll b = query(l,r, i*2+1, mid+1, sr);
    return op(a,b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> q;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (POWN=1; POWN < n; POWN*=2);
    seg.resize(2*POWN);

    build(0,n-1);

    for (int i = 0; i < q; i++) {
        int t, a, b; cin >> t >> a >> b;
        
        for (int i = POWN; i < 2*POWN; i++) debug("%d ", seg[i]);
        debugln("");
        
        if (t == 1) update(a-1,a-1,[b](ll x){return b;});
        else cout << query(a-1,b-1) << '\n';
        for (int i = POWN; i < 2*POWN; i++) debug("%d ", seg[i]);
        debugln("");
    }

}