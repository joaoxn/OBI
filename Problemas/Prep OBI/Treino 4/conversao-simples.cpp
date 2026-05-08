#include <bits/stdc++.h>
using namespace std;

string in;

int main() {
    for (int t = 1; cin >> in && in[0] != '-'; ++t) {
        if (in.size() >= 2 && in[1] == 'x') {
            int decimal = stoi(in, nullptr, 16);
            printf("%d\n", decimal);
        } else {
            int decimal = stoi(in);
            cout << "0x" << hex << uppercase << decimal << "\n";
        }
    }

    return 0;
}