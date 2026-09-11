#include <bits/stdc++.h>
using namespace std;

#define debug(args...) do{ printf(args); fflush(stdout); }while(0)
#define debugln(args...) do{ debug(args); debug("\n"); }while(0)

typedef long long ll;

int n, POWN;
vector<ll> v;

vector<ll> seg;

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
}

void update(ll l, ll r, ll val, ll i=1, ll sl=0, ll sr=POWN-1) {
    if (sr < l || sl > r) return;
    if (sl == sr) {
        seg[i] = val;
        return;
    }

    ll mid = (sl+sr)>>1;
    update(l,r,val, i*2, sl, mid);
    update(l,r,val, i*2+1, mid+1, sr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    ll x;
    while (cin >> x) {
        v.push_back(x);
    }
    n = v.size();

    for (POWN=1; POWN < n; POWN*=2);
    seg.resize(4*POWN);


    build(0,9);
    update(0,2, 69);


    for_each(seg.begin()+16,seg.end(), [](ll x){cout << x << ' ';});
}