#include <bits/stdc++.h>
using namespace std;

int n;
int a, b, c;
const int mod = 1e9+7;

int exp(int a, int b) {
    if (b == 0) return 1;
    if (a == 0) return 0;

    if (b%2==0) {
        long long calc = exp(a,b/2);
        return calc*calc % mod;
    } else {
        long long calc = exp(a,b/2);
        return (calc*calc % mod)*a % mod;
    }
}

int main() {
    scanf("%d", &n);
    for (int t = 0; t < n; t++) {
        scanf("%d %d %d", &a, &b, &c);

        printf("%d\n", exp(a,exp(b,c)) % mod);
    }

    return 0;
}
