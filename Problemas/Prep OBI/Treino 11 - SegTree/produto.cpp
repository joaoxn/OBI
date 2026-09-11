#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //printf(args)
#define debugln(args...) do{ debug(args);debug("\n"); }while(0)
typedef long long ll;


int n, k, POWN;
vector<int> v;
vector<int> seg;

void build(int i=1, int sl=0, int sr=POWN-1) {
    if (sl == sr) {
        if (sl >= v.size()) seg[i] = 1;
        else seg[i] = v[sl];
        return;
    }

    int mid = (sl+sr)/2;
    build(i*2,sl,mid);
    build(i*2+1,mid+1,sr);
    seg[i] = seg[i*2] * seg[i*2+1];
}

// void change(int i, int v) {
//     if (i <= 0) return;

//     if (i >= POWN) seg[i] = clamp(v,-1,1);
//     else seg[i] = seg[i*2] * seg[i*2+1];

//     change(i/2, v);
// }

void update(int l, int r, int val, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return;
    if (sl == sr) {
        seg[i] = clamp(val, -1, 1);
        return;
    }

    int mid = (sl+sr)/2;
    update(l,r,val, i*2, sl, mid);
    update(l,r,val, i*2+1, mid+1, sr);
    seg[i] = seg[i*2] * seg[i*2+1];
}

int query(int l, int r, int i=1, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return 1;
    if (l <= sl && sr <= r) return seg[i];

    int mid = (sl+sr)/2;
    int a = query(l,r, i*2, sl, mid);
    int b = query(l,r, i*2+1, mid+1, sr);
    return a * b;
}

int main() {
    while (cin >> n >> k) {
        for (POWN = 1; POWN < n; POWN*=2);
        v.resize(n);
        seg.resize(2*POWN);
        
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            v[i] = clamp(x, -1, 1);
        }

        build();
        for (int x : seg) debug("%d ", x);
        debugln("");

        for (int i = 0; i < k; i++) {
            char t; cin >> t;
            int a, b; cin >> a >> b;
            
            if (t == 'C') {
                a--;
                update(a,a,b);
                for (int x : seg) debug("%2d ", x);
                debugln("");
            } else {
                a--; b--;
                int q = query(a,b);
                cout << (q==1 ? '+' : q==-1 ? '-' : '0');
            }
        }
        cout << '\n';
    }
}
