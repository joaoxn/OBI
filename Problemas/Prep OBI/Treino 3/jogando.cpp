#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
    while (scanf("%d", &n) && n != 0) {
        v.clear();
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        while (q.size() >= 2) {
            int x = q.front();
            q.pop();
            v.push_back(x);

            x = q.front();
            q.pop();
            q.push(x);
        }

        printf("Discarded cards: ");
        for (int i = 0; i < v.size()-1; i++) {
            printf("%d, ", v[i]);
        }
        printf("%d\n", v[v.size()-1]);
        printf("Remaining card: %d\n", q.front());
    }
}