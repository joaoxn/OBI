#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int T, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(0);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        cout << (pow(2,n)-1) << '\n';
    }

    return 0;
}