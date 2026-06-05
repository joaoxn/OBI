#include <bits/stdc++.h>
using namespace std;

int n;
int expr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i <= n; i++) {
        int bit;
        cin >> bit;
        expr <<= 1;
        expr |= bit;
    }

    int counts = 0;
    while (expr > 1) {
        counts++;
        if (expr%2==0) expr >>= 1;
        else {
            int res = 1;
            for (int i = 0; i <= n; i++) {
                int bit = (expr >> i) & 1;
                if (!bit) continue;
                res ^= (3 << i); // bits: 11
            }
            expr = res;
        }
    }

    cout << counts << "\n";

    return 0;
}
/*
x³(x+1)+1(x+1) +1
x⁴+x³ + x+1 +1

01001
11000
^
00011 = 11011
^
00001 = 11010

*/
