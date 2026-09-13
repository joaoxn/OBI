// https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    bool possible = n % 4 == 0 || n % 4 == 3;

    if (!possible) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    vector<vector<int>> gps(2);
    if (n%4==3) {
        gps[0].push_back(1);
        gps[0].push_back(2);
        gps[1].push_back(3);
    }

    int st = n%4==0 ? 1 : 4;
    int end = n;
    int gp = 0;
    
    while (st < end) {
        gps[gp].push_back(st++);
        gps[gp].push_back(end--);
        gp = !gp;
    }

    for (int i = 0; i <= 1; i++) {
        cout << gps[i].size() << '\n';
        for (int x : gps[i]) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}