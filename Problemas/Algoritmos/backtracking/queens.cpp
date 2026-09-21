// https://vjudge.net/problem/CSES-1624
// https://vjudge.net/contest/844996#problem/A

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n = 8;
vector<vector<int>> v(n,vector<int>(n,1));

void place(int pi, int pj) {
    for (int i = 0; i < n; i++) {
        if (v[i][pj]) v[i][pj] = 2;
        if (v[pi][i]) v[pi][i] = 2;
        int j = -(i-pj)+pi;
        if (clamp(j,0,n-1) == j && v[i][j]) v[i][j] = 2;
        j = i-pj+pi;
        if (clamp(j,0,n-1) == j && v[i][j]) v[i][j] = 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '*') v[i][j] = 0;
        }
    }



    return 0;
}

/*
-x+a+b

........
........
........
........
........
........
....x...
........

*/