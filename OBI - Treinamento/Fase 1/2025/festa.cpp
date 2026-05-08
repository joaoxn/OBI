#include <bits/stdc++.h>
using namespace std;

int e, s, l;

int main() {
    scanf("%d %d %d", &e, &s, &l);
    int dist;
    if (e >= s && e >= l || e <= s && e <= l) {
        dist = 2*max(abs(e-s),abs(e-l));
    } else {
        dist = 2*abs(e-s)+2*abs(e-l);
    }
    printf("%d", dist);

    return 0;
}