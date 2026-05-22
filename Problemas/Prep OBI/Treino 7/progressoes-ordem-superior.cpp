#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int g;
    for (g = 0; true; g++) {
        bool reduzido = true;
        for (int i = 1; i < n-g; i++) {
            if (a[i-1] != a[i]) {
                reduzido = false;
                break;
            } 
        }
        if (reduzido) break;
        for (int i = 0; i < n-g-1; i++) {
            a[i] = a[i+1]-a[i];
        }

    }
    printf("%d\n", g);

    return 0;
}