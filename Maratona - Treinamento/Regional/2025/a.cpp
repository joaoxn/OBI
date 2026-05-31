#include <bits/stdc++.h>
using namespace std;

int n, m;
int maxv[1001];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            if (x > maxv[j]) maxv[j] = x; 
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += maxv[i];
    }
    printf("%d\n", sum);

    return 0;
}