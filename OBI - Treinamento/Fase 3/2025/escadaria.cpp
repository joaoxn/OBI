// https://neps.academy/br/exercise/3579
// 100/100
// Iniciado: Sun Sep 27 10:17:29 2026
// Finalizado: Sun Sep 27 10:24:38 2026

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

const int INF = INT_MAX;
int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == -1) v[i] = INF;
    }

    for (int i = 1; i < n; i++) {
        if (v[i] == INF && v[i-1] != INF) {
            v[i] = v[i-1]+1;
        } 
    }

    for (int i = n-2; i >= 0; i--) {
        v[i] = min(v[i],v[i+1]+1); 
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ' ;
    }

    return 0;
}