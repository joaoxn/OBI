// Accepted
#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b, c;
int x, y, z;

int32_t main() {
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);
    a -= x;
    b -= y;
    int borrow = max(0LL,min(-a,c));
    a += borrow;
    c -= borrow;
    borrow = max(0LL,min(-b,c));
    b += borrow;
    c -= borrow;
    c += max(0LL,a) + max(0LL,b);
    if (a >= 0 && b >= 0 && c >= z) {
        printf("It is a kind of magic\n");
    } else {
        printf("There are no miracles in life\n");
    }
}