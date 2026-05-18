#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    scanf("%d", &t);
    for (int _t = 0; _t < t; ++_t) {
        int sum = 0;
        int maxv = -70;
        for (int i = 0; i < 7; ++i) {
            int x;
            scanf("%d", &x);
            sum -= x;
            if (x > maxv) maxv = x;
        }
        sum += 2*maxv;
        printf("%d\n", sum);
    }

    return 0;
}