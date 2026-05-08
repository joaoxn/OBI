//
// Created by xnaxg on 07/04/2026.
// Não Resolvido

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int mat[n][n];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            sum += mat[i][j];
        }
    }

    int l = 0, r = n-1;

    for (int i = n-2; i >= 0; i--) {
        int lSum = 0, rSum = 0;
        for (int j = 0; j <= i; j++) {
            lSum += mat[j][l];
            rSum += mat[j][r];
        }

        if (lSum == rSum) {
            for (int j = i; j >= 0; j--) {
                if (mat[j][l] == mat[j][r]) continue;
                if (mat[j][l] > mat[j][r]) {
                    lSum = rSum+1;
                    break;
                }
                rSum = lSum+1;
                break;
            }
        }

        int colExcluded = r;
        if (lSum > rSum) {
            colExcluded = l;
            ++l;
        } else --r;

        for (int j = 0; j <= i; j++) {
            sum -= mat[j][colExcluded];
        }
    }
    cout << sum << "\n";
}

/*
3
5 2 4
3 6 7
10 5 10

4
45 8 3 1
1 10 5 67
4 4 3 18
10 4 7 12

4
17 6 3  1
 1 1 5 31
32 4 3 18
10 4 7 12

3
5 2 1
3 6 7
10 5 10


10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

*/
