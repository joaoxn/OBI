//
// Created by xnaxg on 12/04/2026.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int ts;
    cin >> ts;
    string _;
    getline(cin, _);
    getline(cin, _);
    for (int t = 0; t < ts; t++) {
        if (t > 0) printf("\n");
        int trees = 0;
        map<string,int> m;
        string s;
        while (getline(cin, s)) {
            if (s.empty()) break;
            ++m[s];
            ++trees;
        }
        for (const auto& [k,v] : m) {
            double percentage = 100 * (v/static_cast<double>(trees));
            printf("%s %.4f\n", k.c_str(), percentage);
        }
    }
}
/*
2

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow

Red Alder
Ash

*/