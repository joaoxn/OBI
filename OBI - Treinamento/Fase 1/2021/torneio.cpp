#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int wins = 0;
    for (int i = 0; i < 6; i++) {
        char c; cin >> c;
        wins += c == 'V';
    }
    if (wins == 0) cout << -1;
    else cout << ((6-wins)/2+1);

    return 0;
}