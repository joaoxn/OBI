#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

double xf, yf;
double xs, ys;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> xf >> yf >> xs >> ys;
    double res = sqrt((xs-xf)*(xs-xf)+(ys-yf)*(ys-yf));

    cout << setprecision(4) << fixed;
    cout << res << '\n';

    return 0;
}