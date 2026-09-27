// https://neps.academy/br/exercise/3582
// 29/100
// Iniciado: Sun Sep 27 13:08:43 2026
// 29 pontos em Sun Sep 27 13:38:37 2026 (Subtarefas 2 e 3)
// O(n²+n*q) = O(n²)

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define IGN if (0)
#define fi first
#define se second
typedef long long ll;
typedef pair<long,long> pll;

ll n, q, k;
vector<ll> a;
set<pll> p;

ll energ(ll i, ll j) {
    return abs(i-j)+abs(a[i]-a[j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (energ(i,j) == k) p.insert({i,j});
        }
    }
    cout << p.size() << '\n';


    while (q--) {
        int d; cin >> d;
        d--;

        for (auto it = p.begin(); it != p.end();) {
            auto x = *it;
            if (x.fi <= d && d <= x.se) {
                it = p.erase(it,next(it));
            } else it++;
        }

        cout << p.size() << '\n';
    }

    return 0;
}

/*
n <= 2*10^5
Tempo máximo: O(nlogn)

Soluções:
    O(n²): n <= 10^4
    Calcular pares i,j onde E(i,j) = K em O(n²)
    para cada di, iterar pares encontrados em O(n*q)
    remover pares onde i <= d <= j, em O(1) com set
    em O(n² + n*q), sendo q < N, ou seja: O(n²)
    

*/