#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

long long n, a, b;

long long gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

long long lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> n >> a >> b;
        if (n == 0 && a == 0 && b == 0) break;

        // ans = n/a + n/b - n/lcm(a,b)
        cout << (n/a + n/b - n/lcm(a,b)) << '\n';
    }

    return 0;
}