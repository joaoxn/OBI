//
// Created by xnaxg on 02/04/2026.
//

#include <algorithm>
#include <iostream>

using namespace std;


int n, s;
int p[50];
int chosen[300];

int solve(int i, int sum) {
    if (sum == s) return i;
    if (sum > s) return -1;

    for (int j = n-1; j >= 0; j--) {
        chosen[i] = j;
        int sol = solve(i+1, sum+p[j]);
        if (sol != -1) return sol;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    for (int c = 0; c < t; c++) {
        cin >> n >> s;

        for (int j = 0; j < n; j++) {
            cin >> p[j];
        }

        int i = solve(0,0);
        if (i == -1) {
            cout << "impossible\n";
            continue;
        }

        int sol[i];
        for (int j = 0; j < i; j++) {
            sol[j] = p[chosen[j]];
        }
        sort(sol, sol+i, greater<int>());

        cout << "Case " << c+1 << ": ";
        cout << "[" << i << "] ";
        for (int j = 0; j < i; j++) {
            cout << sol[j] << " ";
        }
        cout << "\n";
    }
}
