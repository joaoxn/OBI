#include <iostream>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    int balance[n] = {};
    int original = 0;

    for (int i = 0; i < m; i++) {
        int x, v, y;
        cin >> x >> v >> y;

        balance[x] += v;
        balance[y] -= v;
        original += v;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (balance[i] >= 0) continue;
        sum -= balance[i];
    }

    cout << (original == sum ? 'N' : 'S') << endl << sum << endl;

    return 0;
}
