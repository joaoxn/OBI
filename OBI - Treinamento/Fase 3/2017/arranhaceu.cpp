// https://olimpiada.ic.unicamp.br/pratique/ps/2017/f3/arranhaceu/
// 100/100

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int POWN;
int n, q;
vector<int> v;
vector<int> seg;

void build(int i, int l, int r, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return;
    if (sl == sr) {
        seg[i] = v[sl];
        return;
    }

    int mid = (sl+sr)/2;
    build(i*2,l,r, sl,mid);
    build(i*2+1,l,r, mid+1,sr);
    seg[i] = seg[i*2]+seg[i*2+1];
}

void update(int i, int k, int val, int sl=0, int sr=POWN-1) {
    if (sr < k || sl > k) return;
    if (sl == sr) {
        seg[i] = val;
        return;
    }

    int mid = (sl+sr)/2;
    update(i*2,k,val, sl,mid);
    update(i*2+1,k,val, mid+1,sr);
    seg[i] = seg[i*2] + seg[i*2+1];
}

int query(int i, int l, int r, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return 0;
    if (l <= sl && sr <= r) return seg[i];
    if (sl == sr) {
        return seg[i];
    }

    int mid = (sl+sr)/2;
    int a = query(i*2,l,r, sl,mid);
    int b = query(i*2+1,l,r, mid+1,sr);
    return a+b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (POWN=1;POWN < n; POWN*=2);
    v.resize(n);
    seg.resize(2*POWN);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    build(1, 0,n-1);

    for (int i = 0; i < q; i++) {
        int isQuery; cin >> isQuery;
        if (isQuery) {
            int k; cin >> k;
            cout << query(1,0,k-1) << '\n';
        } else {
            int k, p; cin >> k >> p;
            update(1,k-1,p);
        }
    }

    // for (int i = 1; i < 2*POWN; i++) {
    //     cout << seg[i] << ' ';
    //     if (i == 1 || i == 3 || i == 7 || i == 15) cout << '\n';
    // }

    return 0;
}