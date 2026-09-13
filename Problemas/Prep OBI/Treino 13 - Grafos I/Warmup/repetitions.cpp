#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    int maxv = 0;
    char last = ' ';
    int amt = 0;
    for (char c : s) {
        if (c == last) amt++;
        else {
            last = c;
            if (amt > maxv) maxv = amt;
            amt = 1;
        }
    }

    cout << max(maxv,amt);

    return 0;
}