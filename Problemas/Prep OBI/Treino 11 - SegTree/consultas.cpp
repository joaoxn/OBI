#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //printf(args)
#define debugln(args...) do{ debug(args);debug("\n"); }while(0)
typedef long long ll;

int n, c, POWN;
vector<ll> seg;
vector<ll> lazy;

void descendLazy(int i, int sl, int sr) {
    if (sl == sr) return;
    debugln("lazy[%d]=%d", i,lazy[i]);

    ll increase = lazy[i] * (sr-sl+1)/2;

    lazy[i*2] += lazy[i];
    lazy[i*2+1] += lazy[i];
    seg[i*2] += increase;
    seg[i*2+1] += increase;
    lazy[i] = 0;
}

void update(int l, int r, ll val, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return;
    if (l <= sl && sr <= r) {
        ll increase = val * (sr-sl+1);
        seg[i] += increase;
        lazy[i] += val;
        return;
    }

    descendLazy(i, sl, sr);

    int mid = (sl+sr)>>1;
    update(l,r,val, i*2,sl,mid);
    update(l,r,val, i*2+1,mid+1,sr);
    seg[i] = seg[i*2] + seg[i*2+1];
}

ll query(int l, int r, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return 0;
    if (l <= sl && sr <= r) return seg[i];
    
    descendLazy(i, sl, sr);

    int mid = (sl+sr)>>1;
    ll a = query(l,r, i*2,sl,mid);
    ll b = query(l,r, i*2+1,mid+1,sr);
    return a+b;
}

int main() {
    int T; cin >> T;
    for (int _ = 0; _ < T; _++) {

        cin >> n >> c;
        for (POWN = 1; POWN < n; POWN*=2);
        seg.clear();
        seg.resize(2*POWN);
        lazy.clear();
        lazy.resize(2*POWN);

        for (int i = 0; i < c; i++) {
            int t, p, q; cin >> t >> p >> q; p--;q--;
            if (t == 0) {
                ll v; cin >> v;
                update(p,q,v);
            } else {
                cout << query(p,q) << '\n';
            }
        }
        for (int i = 1; i < seg.size(); i++) debug("\t%d", seg[i]);
        debugln("");
        for (int i = 1; i < lazy.size(); i++) debug("\t%d", lazy[i]);
        debugln("");
    }
}