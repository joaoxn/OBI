//
// Created by xnaxg on 22/03/2026.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        map<set<int>, int> map;
        for (int i = 0; i < n; i++) {
            set<int> courses;
            for (int j = 0; j < 5; j++) {
                int course;
                cin >> course;
                courses.insert(course);
            }
            map[courses]++;
        }
        pair<int, int> max = make_pair(0, 0);
        for (auto it : map) {
            int count = it.second;
            if (count > max.first) {
                max.first = count;
                max.second = count;
            } else if (count == max.first)
                max.second += count;
        }
        cout << max.second << "\n";
    }

    return 0;
}

/* INPUT
3
100 101 102 103 488
100 200 300 101 102
103 102 101 488 100
3
200 202 204 206 208
123 234 345 456 321
100 200 300 400 444
4
100 101 102 103 104
104 103 102 101 100
200 202 204 203 201
201 203 204 202 200
6
1 1 1 1 1
2 2 2 2 2
1 1 1 1 1
3 3 3 3 3
2 2 2 2 2
1 1 1 1 1
0
*/

/* OUTPUT
2
3
4
3
*/
