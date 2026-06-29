// 100/100

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int d[5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 4; i >= 0; i--) {
        cin >> d[i];
    }
    
    int res = 0;

    for (int i = 0; i < 5; i++) {
        if (d[i]) res += pow(2,i);
    }

    cout << res;

    return 0;
}