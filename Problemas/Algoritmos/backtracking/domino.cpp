//
// Created by xnaxg on 27/03/2026.
//

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> dominoes;
vector<pair<int,int>> curr;
vector<pair<int,int>> choices;

bool solve() {
    if (curr.size() == dominoes.size()) return true;

    for (auto& dm : choices) {
        if (!curr.empty() && dm.first != curr.back().second)
            continue;
        curr.push_back(dm);

        solve();

    }
    curr.pop_back();
    return false;
}

int main() {
    int n;
    cin >> n;
    dominoes.resize(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pair p(a,b);
        dominoes[i] = p;
    }
    for (int i = 0; i < n; i++) {
        if (dominoes[i].first != dominoes[i].second) {
            pair<int,int> dm = dominoes[i];
            swap(dm.first, dm.second);
            dominoes.push_back(dm);
        }
    }
    choices = dominoes;
    solve();
}

/*
6
1 4
1 5
5 3
3 2
2 6
6 2
6
2 1
4 3
1 3
4 5
2 4
1 5
6
2 1
4 2
6 3
4 4
2 4
1 5
6
2 3
2 1
3 4
4 5
6 5
5 5
0
*/