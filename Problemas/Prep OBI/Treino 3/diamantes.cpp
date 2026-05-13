#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int scopes = 0;
        int diamonds = 0;
        for (char c : s) {
            if (c == '<') {
                scopes++;
            } else if (c == '>' && scopes > 0) {
                scopes--;
                diamonds++;
            }
        }
        printf("%d\n", diamonds);
    }
 
    return 0;
}