// 100/100 - https://judge.beecrowd.com/pt/problems/view/2330
#include <bits/stdc++.h>
using namespace std;

int n, l;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> vendors;
int counts[1001];

int main() {
    scanf("%d %d", &n, &l);
    queue<int> calls;
    for (int i = 0; i < l; i++) {
        int t;
        scanf("%d", &t);
        calls.push(t);
    }
    for (int i = 1; i <= n; i++) {
        vendors.push({0,i});
    }

    while (!calls.empty()) {
        int t = calls.front(); calls.pop();
        pair<int,int> v = vendors.top(); vendors.pop();
        counts[v.second]++;
        vendors.push({v.first+t,v.second});
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, counts[i]);
    }

    return 0;
}