#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int sum = (n+2)*(n+1)/2;
    cout << sum << '\n';

    return 0;
}