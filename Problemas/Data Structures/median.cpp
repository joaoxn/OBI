//
// Created by xnaxg on 22/03/2026.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int value;
    while (cin >> value) {
        v.push_back(value);
        sort(v.begin(), v.end());
        if (v.size() % 2 == 0) {
            cout << (v[v.size()/2 -1] + v[v.size()/2])/2 << "\n";
        } else {
            cout << v[(v.size()-1)/2] << "\n";
        }
    }

    return 0;
}
