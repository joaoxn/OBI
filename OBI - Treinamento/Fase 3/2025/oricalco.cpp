// !WA

#include <bits/stdc++.h>
using namespace std;

#define debug(args...)
// #define debug(args...) fprintf(stderr, args)

int n, k;
vector<vector<int>> sp;
vector<int> pref;
int logn;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    logn = __lg(n);
    sp.resize(n,vector<int>(logn+1));
    pref.resize(n+1);

    for (int i = 0; i < n; i++) {
        cin >> sp[i][0];
        pref[i+1] = pref[i]+sp[i][0];
    }

    for (int j = 1; j <= logn; j++) {
        for (int i = 0; i < n; i++) {
            int i2 = i+(1<<(j-1));
            if (i2 < n)
                sp[i][j] = sp[i][j-1] | sp[i2][j-1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= logn; j++) {
            debug("%d ", sp[i][j]);
        }
        debug("\n");
    }

    int maxred = 0;
    int len = n;
    if (n > k) len = n - (n-k)%(k-1);
    
    for (int i = 0; i < n-len+1; i++) {
        int r = i+len-1;

        int j = 0;
        for (int pw = 2; pw <= len; pw*=2) j++;
        
        int imp = sp[i][j] | sp[i+len-(1<<j)][j];
        int prevSum = pref[r+1]-pref[i];
        maxred = max(maxred, prevSum-imp);
    }

    cout << pref[n]-maxred << '\n';

    return 0;
}