#include <bits/stdc++.h>
using namespace std;

int l, a, p, r;

int main() {
    scanf("%d %d %d %d", &l, &a, &p, &r);
    
    int diag = l*l+a*a+p*p;
    printf(2*r * 2*r >= diag ? "S\n" : "N\n");

    return 0;
}