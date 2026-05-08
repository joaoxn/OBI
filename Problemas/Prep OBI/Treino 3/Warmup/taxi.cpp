#include <bits/stdc++.h>
using namespace std;

double a, g, ra, rg;

int main() {
    scanf("%lf %lf %lf %lf", &a, &g, &ra, &rg);
    double t1 = ra/a;
    double t2 = rg/g;
    if (t1 > t2) {
        printf("A\n");
    } else {
        printf("G\n");
    }

    return 0;
}
