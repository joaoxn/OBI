//
// Created by xnaxg on 02/04/2026.
//

#include <algorithm>
#include <iostream>

using namespace std;

int n = 23;

int op(int a, int o, int b) {
    switch (o) {
        case 0: return a + b;
        case 1: return a - b;
        case 2: return a * b;
        default: return 0;
    }
}

string solve(int _a, int b, int c, int d, int e) {
    int a[] = {_a,b,c,d,e};
    do {
        for (int o1 = 0; o1 < 3; o1++) {
            for (int o2 = 0; o2 < 3; o2++) {
                for (int o3 = 0; o3 < 3; o3++) {
                    for (int o4 = 0; o4 < 2; o4++) {
                        int res = op(op(op(op(a[0],o1,a[1]),o2,a[2]),o3,a[3]),o4,a[4]);
                        if (res == n) return "Possible";
                    }
                }
            }
        }
    } while (next_permutation(a,a+5));
    return "Impossible";
}

int main() {
    while (true) {
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        // int temp;
        // cin >> temp;
        // if (temp != 0) n = temp;
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) break;

        cout << solve(a,b,c,d,e) << "\n";
    }
}

/*
1 1 1 1 1
1 2 3 4 5
2 3 5 7 11
0 0 0 0 0



*/