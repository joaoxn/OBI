#include <iostream>

using namespace std;

pair<int, int> calc() {
    int l, c;
    cin >> l >> c;

    int t2;
    int t1 = t2 = 0;

    t1 = l * c + (l-1)*(c-1);
    t2 = (l-1)*2 + (c-1)*2;

    return {t1, t2};
}

int main() {
    const auto res = calc();
    cout << res.first << endl << res.second << endl;

    return 0;
}
