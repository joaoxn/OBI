// 100/100 - https://judge.beecrowd.com/pt/problems/view/3050
#include <bits/stdc++.h>
using namespace std;

int n;
int a[200101];

int main() {
    scanf("%d", &n);
    int pa=0, pb=0; // pa < pb
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        if (a[i] > a[pb]) {
            pa = pb;
            pb = i;
        } else if (a[i] > a[pa]) {
            pa = i;
        }
    }

    for (int i = pb+1; i <= n; i++) {
        if (a[i]+(i-pb) > a[pb]) {
            pb = i;
        }
    }
    
    for (int i = pa-1; i > 0; i--) {
        if (a[i]+(pa-i) > a[pa]) {
            pa = i;
        }
    }

    int ans = abs(pb-pa) + a[pa] + a[pb];
    printf("%d\n", ans);

    return 0;
}