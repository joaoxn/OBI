#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> mt;

int main() {
    cin >> n;
    mt.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mt[i][j];
        }
    }

    int cs[] = {mt[0][0],mt[0][n-1],mt[n-1][n-1],mt[n-1][0]};
    int mini = 3;
    int minv = INT_MAX;
    for (int i = 0; i < 4; i++) {
        if (cs[i] < minv) {
            minv = cs[i];
            mini = i;
        }
    }
    cout << mini;
}