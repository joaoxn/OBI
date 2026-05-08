//
// Created by xnaxg on 07/04/2026.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> even, odd;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }
    sort(even.begin(), even.end());
    sort(odd.rbegin(), odd.rend());

    for (int i : even) {
        cout << i << "\n";
    }
    for (int i = 0; i < odd.size(); i++) {
        cout << odd[i] << "\n";
    }
}