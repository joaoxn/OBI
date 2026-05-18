#include <bits/stdc++.h>
using namespace std;

int t;
long long n, a, b;

int main() {
    scanf("%d", &t);
    for (int _t = 0; _t < t; ++_t) {
        scanf("%lld %lld %lld", &n, &a, &b);

        long long cost;
        if (b > 3*a) {
            cost = a*n;
        } else if (b > 2*a) {
            cost = b*(n/3) + a*(n%3);
        } else if (b > a) {
            cost = b*(n/3);
            if (n%3==2) cost += b;
            else cost += a*(n%3);
        } else {
            cost = b*ceil(n/3.0);
        }

        printf("%lld\n", cost);

    }

    return 0;
}