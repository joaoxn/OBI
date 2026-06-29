// 100/100

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    int v[4] = {10,5,2,1};
    int counts = 0;

    for (int i = 0; i < 4; i++) {
        counts += n/v[i];
        n %= v[i];
    }

    cout << counts;

    return 0;
}