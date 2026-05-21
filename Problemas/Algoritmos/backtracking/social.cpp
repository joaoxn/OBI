//
// Created by xnaxg on 31/03/2026.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

struct Constraint {
    int a, b, c;
};

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        Constraint cs[m];
        for (int i = 0; i < m; i++) {
            cin >> cs[i].a >> cs[i].b >> cs[i].c;
        }
        vector<int> teens(n);
        for (int i = 0; i < n; i++)
            teens[i] = i;

        int solutions = 0;
        do {
            bool isSolution = true;
            for (int i = 0; i < m; i++) {
                Constraint c = cs[i];
                int a_i = find(teens.begin(),teens.end(),c.a) - teens.begin();
                int b_i = find(teens.begin(),teens.end(),c.b) - teens.begin();

                if (c.c > 0 && abs(a_i-b_i) > c.c || c.c < 0 && abs(a_i-b_i) < abs(c.c)) {
                    isSolution = false;
                    break;
                }
            }
            if (isSolution) solutions++;
        } while (next_permutation(teens.begin(), teens.end()));

        cout << solutions << "\n";
    }
}

/*
3 1
0 1 -2
3 0
4 1
0 1 -3
4 2
2 3 1
0 1 -2
0 0

*/
