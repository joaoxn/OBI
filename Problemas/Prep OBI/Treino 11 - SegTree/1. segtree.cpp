#include <bits/stdc++.h>
using namespace std;

#define debug(args...) do{ printf(args); fflush(stdout); }while(0)
#define debugln(args...) do{ debug(args); debug("\n"); }while(0)

typedef long long ll;

int n, POWN;
vector<ll> v;
vector<ll> seg;

void build(int l, int r, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return;
    if (sl == sr) {
        debugln("i,sl,sr=(%d,%d,%d)",i,sl,sr);
        seg[i] = v[sl];
        return;
    }

    int mid = (sl+sr)>>1;
    build(l,r, i*2, sl, mid);
    build(l,r, i*2+1, mid+1, sr);
}

void update(ll val, int pos, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < pos || sl > pos) return; // Out of range
    if (sl == sr) {
        seg[i] = val; // Alteração do valor em pos
        return;
    }

    int mid = (sl+sr)/2;
    update(l,r,val, i*2, sl,mid);
    update(l,r,val, i*2+1, mid+1,sr);
    seg[i] = seg[i*2] + seg[i*2+1]; // Operação de Merge
}
for (int i = 0; i < n; i++) up[i][0] = parent[i];
for (int j = 1; j < log(n); j++)
    for (int i = 0; i < n; i++)
        up[i][j] = up[up[i][j-1]][j-1];

int v = i;
for (int j = log(n)-1; j >= 0; j--) {
    if (k & 1<<j) v = up[v][j];
}


ll query(int l, int r, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return NEUTRO; // Elemento neutro
    if (l <= sl && sr <= r) return seg[i];

    int mid = (sl+sr)>>1;
    ll a = query(l,r, i*2, sl, mid);
    ll b = query(l,r, i*2+1, mid+1, sr);
    // Opcional: Se NEUTRO não for definido, selecionar valor único
    // para identificar (ex.: NEUTRO = -1)
    if (a == NEUTRO) return b; 
    if (b == NEUTRO) return a;
    return a + b; // Operação de Merge
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
    seg.resize(2*POWN);


    build(0,9);
    update(x,i);


    for_each(seg.begin()+POWN,seg.end(), [](ll x){cout << x << ' ';});
}