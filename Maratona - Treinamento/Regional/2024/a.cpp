#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    k = k-n+1;
    cout << (k/n);
}