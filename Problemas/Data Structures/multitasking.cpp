//
// Created by xnaxg on 22/03/2026.
//

#include <bitset>
#include <iostream>
using namespace std;

bool occupy(bitset<100001> &set, int start, int end) {
    for (int i = start; i < end && i <= 100000; i++) {
        bool occupied = set.test(i);
        if (occupied)
            return false;
        set[i] = true;
    }
    return true;
}

int main() {
    while (true) {
        MAIN:
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        bitset<100001> set;

        for (int i = 0; i < n; i++) {
            int start, end;
            cin >> start >> end;
            if (!occupy(set, start, end)) {
                cout << "CONFLICT\n";
                goto MAIN;
            }
        }
        for (int i = 0; i < m; i++) {
            int start, end, rep_interval;
            cin >> start >> end >> rep_interval;
            int duration = end-start;
            for (int j = start; j <= 100000; j += rep_interval) {
                if (!occupy(set, j, j+duration)) {
                    cout << "CONFLICT\n";
                    goto MAIN;
                }
            }
        }
        cout << "NO CONFLICT\n";
    }

    return 0;
}


/*

---- ---- ---- ---- -
    -    -    -    -
 --    --    --    --

*/