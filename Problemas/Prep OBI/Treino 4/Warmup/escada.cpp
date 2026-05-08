#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);

    int sum = 0;
    int stair = 0;
    int h[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", h+i);
        sum += h[i];
        stair += i+1;
    }

    int xtra = 0;
    while (stair < sum) {
        stair += n;
        ++xtra;
    }

    if (stair != sum) {
        printf("-1\n");
        return 0;
    }

    int posi = 0;
    for (int i = 0; i < n; i++) {
        int diff = h[i]-(i+1+xtra);
        posi += max(0, diff);
    }

    printf("%d\n", posi);

    return 0;
}