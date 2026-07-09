#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int a, b, c, d;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c >> d;
    
    int deno = lcm(b,d);
    int nume = a*(deno/b)+c*(deno/d);

    int fracgcd = gcd(nume,deno);

    deno /= fracgcd;
    nume /= fracgcd;

    cout << nume << ' ' << deno << '\n';

    return 0;
}