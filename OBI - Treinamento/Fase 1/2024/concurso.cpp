#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);

    cout << a[n-k] << "\n";
}