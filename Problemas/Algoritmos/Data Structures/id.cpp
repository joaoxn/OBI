//
// Created by xnaxg on 22/03/2026.
//

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string in;
    while (true) {
        cin >> in;
        if (in == "#") break;
        size_t size = in.size();
        char *str = new char[size + 1];
        copy(in.begin(), in.end(), str);
        str[size] = '\0';

        bool success = next_permutation(str, str + size);
        cout << (success ? str : "No Successor") << "\n";

        delete[] str;
    }
    return 0;
}
