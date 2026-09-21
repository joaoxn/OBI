// https://vjudge.net/problem/Kattis-veci
// https://vjudge.net/contest/844995#problem/B

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

vector<int> n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    while (cin >> c) {
        c -= '0';
        n.push_back(c);
    }

    bool success = next_permutation(n.begin(),n.end());
    if (!success) cout << 0;
    else {
        for (int d : n) cout << d;
    }

    return 0;
}