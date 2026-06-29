#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //printf(args)

int m, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> m >> n) {
        long long mf=1, nf=1;

        while (m > 1) {
            mf *= m;
            debug("mf=%d\n",mf);
            m--;
        }
        
        while (n > 1) {
            nf *= n;
            debug("nf=%d\n",nf);
            n--;
        }

        cout << (mf+nf) << '\n';
    }

    return 0;
}