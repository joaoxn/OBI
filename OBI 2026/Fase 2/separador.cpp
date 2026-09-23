// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define debugln(args...) printf(args); printf("\n")
typedef long long ll;

int n, f;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<vector<int>> fs;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> f;
    fs.resize(f+1);

    for (int i = 1; i <= f; i++) pq.push({0,i});

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pair<int,int> minf = pq.top(); pq.pop();
        minf.first += x;
        pq.push(minf);
        fs[minf.second].push_back(x);
    }

    for (int i = 1; i <= f; i++) {
        for (int x : fs[i]) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}