#include <bits/stdc++.h>
using namespace std;

int a, b;
int s1[100001];
int s2[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> s1[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> s2[i];
    }

    int j = 0;
    for (int i = 0; i < a; i++) {
        if (s1[i] == s2[j]) {
            j++;
        }
    }

    cout << (j == b ? 'S' : 'N');

    return 0;
}