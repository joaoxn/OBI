#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[10001];
int c[10001];

struct Caixa {
    int time;
    int id;
    int mult() {
        return v[id];
    }
    
    bool operator>(const Caixa& other) const {
        if (time == other.time)
        return id > other.id;
        return time > other.time;
    }
};

priority_queue<Caixa, vector<Caixa>, greater<Caixa>> pq;

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> c[i];
        if (i < n) {
            pq.push(Caixa{v[i]*c[i],i});
        }
    }

    for (int i = n; i < m; i++) {
        Caixa cx = pq.top();
        pq.pop();
        cx.time += cx.mult()*c[i];
        pq.push(cx);
    }

    int time;
    while (!pq.empty()) {
        if (pq.size() == 1) {
            time = pq.top().time;
        }
        pq.pop();
    }
    printf("%d\n", time);

    return 0;
}

/*

2 4
1 2
2 3 4 5

2s 6s
4 5

6s 6s
5

11s 6s

*/
