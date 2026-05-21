#include <iostream>
#include <vector>

using namespace std;

bool solve(int n, vector<int>& bars) {
    int p = bars.size();
    int limitBmask = (1 << p);

    for (int bmask = 0; bmask < limitBmask; bmask++) {
        int sum = 0;
        for (int j = 0; j < p; j++) {
            if (bmask & (1 << j)) {
                sum += bars[j];
                if (sum == n) return true;
                if (sum > n) break;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, p;
        cin >> n >> p;
        vector<int> bars;
        bool solvable = false;
        for (int j = 0; j < p; j++) {
            int b;
            cin >> b;
            if (b == n)
                solvable = true;
            else if (b < n)
                bars.push_back(b);
        }
        if (solvable || n == 0 || solve(n, bars))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}