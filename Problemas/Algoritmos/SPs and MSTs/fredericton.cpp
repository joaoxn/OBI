#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int T;
int n, m, q;
map<string,int> code;
string name[100];

vector<set<pair<int,int>>> grafo;
int dist[100];
int travel[100];
int maxtravel[100];
bool vis[100];

void bfs() {
    queue<int> q;
    q.push(n-1);
    maxtravel[n-1] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto a : grafo[u]) {
            int v = a.second;
            int newmax = maxtravel[u]+1;
            if (newmax >= maxtravel[v]) continue;
            q.push(v);
        }
    }
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        grafo.clear();
        grafo.resize(n+1);
        
        memset(vis,0,sizeof vis);
        memset(travel,0,sizeof travel);
        
        for (int i = 0; i < n; i++) {
            dist[i] = INF;
            maxtravel[i] = INF;
        }

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            code[s] = i;
            name[i] = s;
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            string a, b;
            int c;
            cin >> a >> b >> c;
            int ca = code[a], cb = code[b];
            grafo[ca].insert({c,cb});
            grafo[cb].insert({c,ca});
        }
        bfs();
        printf("Scenario #%d\n", t);
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int qry; 
            cin >> qry;

            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
            q.push({0,0});
    
            while (!q.empty()) {
                auto p = q.top(); q.pop();
                int u = p.second;
                if (vis[u]) continue;
                vis[u] = true;
    
                for (pair<int,int> a : grafo[u]) {
                    if (vis[a.second]) continue;
                    int newdist = dist[u]+a.first;
                    if (newdist >= dist[a.second]) continue;
                    int newtravel = travel[u]+1;
                    if (newtravel + maxtravel[a.second] > qry) continue;
                    dist[a.second] = newdist;
                    travel[a.second] = newtravel;
                    q.push({dist[a.second], a.second});
                }
            }
            printf("Total cost of flight(s) is $%d\n", dist[n-1]);
        }
        printf("\n");
    }

    return 0;
}