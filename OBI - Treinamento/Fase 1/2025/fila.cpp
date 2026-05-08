#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int amt = 0;
    int max = -1;
    for (int i = n-1; i >= 0; --i) {
        if (a[i] <= max) ++amt;
        if (a[i] > max) max = a[i];
    }
    printf("%d\n", amt);

    return 0;
}