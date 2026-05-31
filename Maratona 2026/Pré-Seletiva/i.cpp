// Accepted
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, p;
ll a[100101];
ll b[100101];

int32_t main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", a+i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", b+i);
    }
    scanf("%lld", &p);

    sort(a,a+n);
    sort(b,b+n);

    long long ways = 1;
    for (int i = n-1; i >= 0; i--) {
        ll used = (n-1)-i;
        ll k = b[i];
        ll l=0, r=n-1;
        ll amt = (a+n)-lower_bound(a,a+n,k) - used;
        amt %= p;
        ways *= amt;
        ways %= p;
    }
    printf("%lld\n", ways);
}

/*
4
2 3 3 4
1 1 1 3
1000000007

4
1 2 4 4
4 4 4 4
1000000007

*/