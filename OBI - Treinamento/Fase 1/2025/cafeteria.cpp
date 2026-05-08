#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    printf(((c-a)/d)*d >= (c-b) ? "S" : "N");

    return 0;
}