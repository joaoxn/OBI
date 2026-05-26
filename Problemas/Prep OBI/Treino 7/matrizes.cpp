// 100/100 - https://judge.beecrowd.com/pt/problems/view/2385
#include <bits/stdc++.h>
using namespace std;

int n;
long long p, q, r, s, x, y;
int i, j;

long long a(int i, int j) {
    return (p*i+q*j) % x;
}

long long b(int i, int j) {
    return (r*i + s*j) % y;
}

int main() {
    scanf("%d", &n);
    scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &x, &y);
    scanf("%d %d", &i, &j);

    long long ans = 0;
    for (int k = 1; k <= n; k++) {
        ans += a(i,k)*b(k,j);
    }
    printf("%lld\n", ans);

    return 0;
}