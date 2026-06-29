#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, k;
int a[500101];
int pref[500102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i+1]=a[i]+pref[i];
    }

    int counts = 0;

    int l=0, r=0;
    while (l < n && r < n) {
        int sum = pref[r+1]-pref[l];
        
        if (sum > k) l++;
        else if (sum < k) r++;
        else {
            int zerol = l, zeror = r;
            while (zerol > 0 && a[zerol-1]==0) zerol--;
            while (zeror < n-1 && a[zeror+1]==0) zeror++;

            int cl = l-zerol, cr = zeror-r;
            counts += (cl+1)*(cr+1);
            
            r = zeror+1;
        }
    }

    cout << counts << '\n';

    return 0;
}