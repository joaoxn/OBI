#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int custos[3];
    for (int i = 0; i < 3; ++i) {
        scanf("%d", custos+i);
    }
    sort(custos,custos+3);
    int count = 0;
    for (int c : custos) {
        if (n < c) break;
        n -= c;
        count++;
    }
    printf("%d\n", count);

    return 0;
}