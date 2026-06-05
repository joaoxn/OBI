#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    set<string> cards;
    map<char,int> m{{'C',0},{'E',0},{'U',0},{'P',0}};
    for (int i = 0; i < s.size(); i+=3) {
        string str = "";
        char naipe = s[i+2];
        if (m[naipe] == -1) continue;

        for (int j = 0; j < 3; j++) {
            str += s[i+j];
        }
        if (cards.find(str) != cards.end()) {
            m[naipe] = -1;
            continue;
        }
        cards.insert(str);
        m[naipe]++;
    }

    for (char c : {'C','E','U','P'}) {
        if (m[c] == -1) cout << "erro";
        else cout << 13-m[c];
        cout << "\n";
    }

    return 0;
}