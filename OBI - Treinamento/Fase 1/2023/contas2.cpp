#include <bits/stdc++.h>
using namespace std;

int v;
int a[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a,a+3);
    for (int i = 0; i < 3 && v >= 0; i++) {
        v -= a[i];
        if (v < 0) cout << i;
    }
    if (v >= 0) cout << 3;

    return 0;
}