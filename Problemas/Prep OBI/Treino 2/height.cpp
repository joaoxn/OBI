//
// Created by xnaxg on 12/04/2026.
//
#include <bits/stdc++.h>
using namespace std;

int MAX_VSIZE = 3000001;
int v[3000001];

int main() {
    int ts;
    cin >> ts;
    for (int t = 0; t < ts; t++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v,v+n);

        for (int j = 0; j < n; j++) {
            cout << v[j];
            if (j < n-1) cout << " ";
        }
        cout << "\n";
    }
}