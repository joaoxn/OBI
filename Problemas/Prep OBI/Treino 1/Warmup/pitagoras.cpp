#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int a[3];

int mdc(int x, int y) {
    if (y == 0) return x;
    return mdc(y, x%y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> a[0] >> a[1] >> a[2]) {
        sort(a,a+3);
        auto [x,y,z] = a;

        bool pitagorica = (x*x+y*y == z*z);
        bool primitiva = (mdc(x,mdc(y,z)) == 1);

        cout << "tripla";
        if (pitagorica) {
            cout << " pitagorica";
            if (primitiva) cout << " primitiva";
        }
        cout << '\n';
    }

    return 0;
}