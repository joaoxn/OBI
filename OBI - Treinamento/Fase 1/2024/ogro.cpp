#include <bits/stdc++.h>
using namespace std;

int e, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> e >> d;

    int res = -1;
    if (e > d) {
        res = e+d;
    } else {
        res = 2*(d-e);
    }
    cout << res << "\n";
}