#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x != 0) s.push(x);
        else if (!s.empty()) s.pop();
    }
    int soma = 0;
    while (!s.empty()) {
        soma += s.top(); s.pop();
    }
    cout << soma;

    return 0;
}