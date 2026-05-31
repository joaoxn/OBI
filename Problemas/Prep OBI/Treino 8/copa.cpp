#include <bits/stdc++.h>
using namespace std;

struct A {
    int u, v, c;
    bool operator <(const A &other) const {
        return c > other.c;
    }
};

int n, f, r;
vector<set<pair<int,int>>> ferro;
vector<set<pair<int,int>>> rodo;
bool vis[101];

int main() {
    scanf("%d %d %d", &n, &f, &r);
    ferro.resize(n+1);
    rodo.resize(n+1);

    for (int i = 0; i < f; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        ferro[a].insert({c,b});
        ferro[b].insert({c,a});
    }

    for (int i = 0; i < r; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        rodo[a].insert({c,b});
        rodo[b].insert({c,a});
    }
    
    priority_queue<A> q;
    
    for (auto a : ferro[1]) {
        q.push({1,a.second,a.first});
    }
    vis[1] = true;

    while (!q.empty()) {
        auto a = q.top(); q.pop();
        vis[a.u] = true;

        for (auto b : ferro[a.v]) {
            if (vis[b.second]) continue;
            q.push({a.v,b.second,b.first});
        }
    }
}

/*
MST

Prim: Escolher sempre uma ferroviária de menor custo;
- Preencher o restante com rodoviárias de menor custo;

*/