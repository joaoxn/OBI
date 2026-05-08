//
// Created by xnaxg on 22/03/2026.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        multiset<int> ms;
        int paid = 0;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int b;
                cin >> b;
                ms.insert(b);
            }
            multiset<int>::iterator first_it = ms.begin();
            multiset<int>::iterator last_it = ms.end();
            paid += *--last_it - *first_it;

            ms.erase(first_it);
            ms.erase(last_it);
        }
        cout << paid << "\n";
    }
    return 0;
}

/*

1
4 0 10 2 4
3
2 0 0
3 2 2 3
1 1
4
7 1 1 2 2 3 3 4
0
0
1 2
0
-> 10 2 6

5
3 1 2 3
2 1 1
4 10 5 5 1
0
1 2
2
2 1 2
2 1 2
0

*/

