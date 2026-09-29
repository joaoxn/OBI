// https://olimpiada.ic.unicamp.br/pratique/ps/2018/f3/baldes/
// OBI 2018 Fase 3 Nível Sênior
// 100/100

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define fi first.first
#define se first.second
#define th second
typedef pair<pair<int,int>,int> pi3; 

int n, m;
int POWN;
vector<int> v;
vector<pi3> seg;

void build(int l, int r, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return;
    if (sl == sr) {
        seg[i] = {{v[sl],v[sl]},0};
        return;
    }

    int mid = (sl+sr)/2;
    build(l,r, i*2, sl,mid);
    build(l,r, i*2+1, mid+1,sr);
    
    auto a = seg[i*2];
    auto b = seg[i*2+1];
    seg[i].fi = max(a.fi,b.fi);
    seg[i].se = min(a.se,b.se);
    seg[i].th = max(max(abs(a.fi-b.se),abs(b.fi-a.se)),max(a.th,b.th));
}

void add(int x, int pos, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < pos || sl > pos) return;
    if (sl == sr) {
        seg[i].fi = max(seg[i].fi, x);
        seg[i].se = min(seg[i].se, x);
        return;
    }

    int mid = (sl+sr)/2;
    add(x,pos, i*2, sl,mid);
    add(x,pos, i*2+1, mid+1,sr);

    auto a = seg[i*2];
    auto b = seg[i*2+1];
    seg[i].fi = max(a.fi,b.fi);
    seg[i].se = min(a.se,b.se);
    seg[i].th = max(max(abs(a.fi-b.se),abs(b.fi-a.se)),max(a.th,b.th));
}

pi3 query(int l, int r, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return {{},-1};
    if (l <= sl && sr <= r) return seg[i];

    int mid = (sl+sr)/2;
    pi3 a = query(l,r, i*2, sl,mid);
    pi3 b = query(l,r, i*2+1, mid+1,sr);
    
    if (a.th == -1) return b;
    if (b.th == -1) return a;

    pi3 res;
    res.fi = max(a.fi,b.fi);
    res.se = min(a.se,b.se);
    res.th = max(max(abs(a.fi-b.se),abs(b.fi-a.se)),max(a.th,b.th));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    v.resize(n);
    for (POWN = 1; POWN < n; POWN *= 2);
    seg.resize(2*POWN);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    build(0,n-1);

    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        if (t == 1) {
            int p, i; cin >> p >> i;
            add(p,i-1);
        } else {
            int a, b; cin >> a >> b;
            cout << query(a-1,b-1).th << '\n';
        }
    }

    return 0;
}

/*
SegTree
Maximizar diferença de elementos (de diferentes baldes)
na seg, guardar estados:
- maximo em [l,r]
- minimo em [l,r]
- diferença maxima

diferença maxima = max(
    diferença maxima de [l,m]
    diferença maxima de [m+1,r]
    diferenca maxima de uma bola em [l,m] com uma em [m+1,r]
)

*/