// 100/100

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, t;
int a[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a,a+n);

    int counts = 1;
    int oldest = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > oldest+t) {
            counts++;
            oldest = a[i];
        }
    }

    cout << counts;

    return 0;
}