// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> torre;
set<int> nums;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    torre.push_back(n);
    nums.insert(n);
    int c = -1;
    while (true) {
        c++;
        int curr = torre[c];
        int maxc[4];
        int minc[4];
        for (int i = 3; i >= 0; i--) {
            maxc[i] = (curr%10);
            minc[i] = maxc[i];
            curr /= 10;
        }
        // for (int i = 0; i <= 3; i++) {
        //     cout << maxc[i];
        // }
        // cout << "\nmaxc=";
        sort(maxc,maxc+4,greater<int>());
        sort(minc,minc+4);
        
        // for (int i = 0; i <= 3; i++) {
        //     cout << maxc[i];
        // }
        // cout << "\nminc=";
        // for (int i = 0; i <= 3; i++) {
        //     cout << minc[i];
        // }
        // cout << '\n';


        int maxv = 0, minv = 0;
        for (int i = 3; i >= 0; i--) {
            maxv += maxc[i]*pow(10,3-i);
            minv += minc[i]*pow(10,3-i);
        }
        int x = maxv-minv;
        //cout << "maxv-minv="<<maxv<<"-"<<minv<<"="<<x<<'\n';
        if (nums.find(x) != nums.end()) break;
        torre.push_back(x);
        nums.insert(x);
    }

    for (int i = 0; i < torre.size(); i++) {
        cout << torre[i] << '\n';
    }

    return 0;
}