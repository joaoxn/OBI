#include <bits/stdc++.h>
using namespace std;

int n, t;
priority_queue<pair<int,string>> pq;

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        string nome;
        int h;
        cin >> nome >> h;
        pq.push({h,nome});
    }

    priority_queue<string, vector<string>, greater<string>> times[t];
    
    for (int i = 0; !pq.empty(); i = (i+1)%t) {
        times[i].push(pq.top().second);
        pq.pop();
    }

    for (int i = 0; i < t; ++i) {
        printf("Time %d\n", i+1);
        while (!times[i].empty()) {
            printf("%s\n", times[i].top().c_str());
            times[i].pop();
        }
        printf("\n");
    }

    return 0;
}