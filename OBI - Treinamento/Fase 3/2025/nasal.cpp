// https://neps.academy/br/exercise/3581
// 100/100
// Iniciado: Sun Sep 27 10:28:22 2026
// Finalizado: Sun Sep 27 11:37:23 2026

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
typedef long long ll;

int n, k;
vector<ll> a;
vector<ll> b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    priority_queue<ll> pq;
    ll A = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            pq.push(a[i]);
            continue;
        }
        A += a[i]-b[i];
        pq.push(b[i]);
    }
    k++;
    while (k-- > 0 && !pq.empty()) {
        A += pq.top(); pq.pop();
    }

    cout << A;

    return 0;
}

/*
*Maximizar Nasalidade: max(A)

Escolha:
(!vis[i] && ai+A >= B): 
    A = ai+A-B
    B = bi

INTUIÇÃO: 
escolher todos os i onde ai > bi
    A = soma(ai-bi)

somar os k+1 maiores entre os bi escolhidos e os ai não escolhidos
    A += soma(maxk(bi,k+1))


Tempo permitido: O(nlogn)
n <= 10^5
Tempo: O(n)
*/