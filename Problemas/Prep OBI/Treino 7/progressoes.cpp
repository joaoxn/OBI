// 100/100 - https://judge.beecrowd.com/pt/problems/view/2398
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001];
bool flag[100001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n-1; i++) {
        a[i] = a[i+1]-a[i];
    }
    int p = 1;
    for (int i = 0; i < n-2; i++) {
        if (a[i] != a[i+1] && !flag[i]) {
            flag[i+1] = true;
            p++;
        }
    }
    
    printf("%d\n", p);

    return 0;
}