// https://olimpiada.ic.unicamp.br/pratique/ps/2017/f3/postes/
// 100/100

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int trocar=0,reparar=0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x < 50) trocar++;
        else if (x < 85) reparar++;
    }

    cout << trocar << ' ' << reparar;

    return 0;
}