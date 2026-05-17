#include <bits/stdc++.h>
using namespace std;

int n, a, l, p;

int main() {
    scanf("%d %d %d %d", &n, &a, &l, &p);
    
    bool cabe = a >= n && l >= n && p >= n;
    printf(cabe ? "S\n" : "N\n");

    return 0;
}