#include <bits/stdc++.h>
using namespace std;

int n;

vector<pair<int,int>> v;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end(), [](pair<int,int> p1, pair<int,int> p2)->bool {
        if (p1.second != p2.second)
            return p1.second < p2.second;
        return p1.first < p2.first;
    });

    int count = 0;
    int time = 0;
    for (pair<int,int> p : v) {
        if (p.first >= time) {
            ++count;
            time = p.second;
        }
    }
    printf("%d\n", count);

    return 0;
}