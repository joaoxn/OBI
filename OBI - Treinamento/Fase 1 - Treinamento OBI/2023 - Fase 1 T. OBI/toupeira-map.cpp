//
// Created by xnaxg on 01/06/2025.
// Exercício: https://neps.academy/br/exercise/2323
// Mesmo que `./toupeira.cpp`, agora utilizando std::map
// ao invés de array primitivo
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int s, t;
    cin >> s >> t;

    map<int, vector<int>> mapa{};


    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;

        mapa.insert({x, vector<int>{}});
        mapa.insert({y, vector<int>{}});

        mapa.at(x).push_back(y);
        mapa.at(y).push_back(x);
    }



    int p;
    cin >> p;
    int count = 0;
    for (int i = 0; i < p; i++) {
        int n;
        cin >> n;

        int prev;
        cin >> prev;

        bool possible = true;
        for (int j = 1; j < n; j++) {
            int c;
            cin >> c;
            if (!mapa.count(prev)) {
                possible = false;
                prev = c;
                continue;
            }
            vector<int> vect = mapa.at(prev);
            if (find(vect.begin(), vect.end(), c) == vect.end()) {
                possible = false;
            }
            prev = c;
        }
        if (possible) count++;
    }

    cout << count;

    return 0;
}

