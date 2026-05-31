#include <bits/stdc++.h>
using namespace std;

int d[10];
bool has[5];

int main() {
    for (int i = 0; i < 10; i++) {
        scanf("%d", d+i);
        has[d[i]] = true;
    }
    int count = 0;
    for (int i = 1; i <= 4; i++) {
        if (!has[i]) count++;
    }
    printf("%d\n", count);

    return 0;
}