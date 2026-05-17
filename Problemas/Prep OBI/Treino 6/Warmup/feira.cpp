#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    double maxv = 0;
    int bact = -1;
    for (int i = 0; i < n; ++i) {
        int d, c;
        scanf("%d %d", &d, &c);

        double total = c*log2(d);
        if (total > maxv) {
            maxv = total;
            bact = i;
        }
    }
    printf("%d\n", bact);

    return 0;
}

/*
a^b
log2(a^b)/log2(a) = b

2^log2(a^b) = 2^(b*log2(a))
a^b = 2^(b*log2(a))
*/