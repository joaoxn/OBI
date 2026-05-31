#include <bits/stdc++.h>
using namespace std;

int a[3];
int h, l;

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d", a+i);
    }
    scanf("%d %d", &h, &l);
    if (h > l) {
        int temp = h;
        h = l;
        l = temp;
    }
    sort(a,a+3);

    for (int i = 0; i < 2; i++) {
        for (int j = i+1; j < 3; j++) {
            if (a[i] <= h && a[j] <= l) {
                printf("S\n");
                return 0;
            }
        }
    }
    printf("N\n");
    return 0;
}