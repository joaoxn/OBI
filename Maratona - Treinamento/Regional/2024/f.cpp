#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define fi first
#define se second

int n;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y,x%y);
}

pair<int,int> p(int i) {
    if (i == 0) return {1,1};
    auto plus1 = p(i-1);
    plus1.fi += plus1.se;
    int divisor = gcd(max(plus1.fi,plus1.se), min(plus1.fi,plus1.se));
    return {plus1.se/divisor,plus1.fi/divisor};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    auto sol = p(n);
    cout << sol.fi;

    return 0;
}