// TODO: incompleto

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int POWN;
int n, q;
vector<int> v;
vector<int> seg;

void build(int i, int l, int r, int sl=0, int sr=POWN-1) {
    if (sr < l || sl > r) return;
    if (l == r) {
        seg[i] = v[l];
        return;
    }

    int mid = (sl+sr)/2;
    build(i*2,l,r, sl,mid);
    build(i*2+1,l,r, mid+1,sr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (POWN=1;POWN < n; POWN*=2);
    v.resize(n);
    seg.resize(2*POWN+1);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    build(0, 0,n-1);
    for (int i = 0; i <= POWN; i++) {
        cout << seg[i] << ' ';
        if (i == 1 || i == 2 || i == 4 || i == 8) cout << '\n';
    }

    return 0;
}