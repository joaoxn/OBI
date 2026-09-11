#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

int n, m;
vector<vector<char>> g;
vector<vector<int>> parent;

vector<pii> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
string dirChar = "RDLU";

// vector<char> path;
// bool dfs(int i, int j) {
//     vis[i][j] = true;
//     if (g[i][j] == 'B') return true;

//     for (int k = 0; k < 4; k++) {
//         int ni = i+dirs[k].fi;
//         int nj = j+dirs[k].se;
//         if (
//             clamp(ni,0,n) != ni || clamp(nj,0,m) != nj 
//             || g[ni][nj] == '#' || vis[ni][nj]
//         ) continue;

//         path.push_back(dirChar[k]);
//         if (dfs(ni,nj)) return true;
//         path.pop_back();
//     }
//     return false;
// }

void outMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << parent[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    g.resize(n, vector<char>(m));
    parent.resize(n, vector<int>(m,9));

    int ai, aj;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                ai = i;
                aj = j;
            }
        }
    }

    parent[ai][aj] = 8;
    pii v = {-1,-1};

    queue<pii> q; q.push({ai,aj});
    while (!q.empty()) {
        // outMatrix();

        pii u = q.front(); q.pop();
        if (g[u.fi][u.se] == 'B') {
            v = u;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ni = u.fi + dirs[i].fi;
            int nj = u.se + dirs[i].se;
            if (
                clamp(ni,0,n) != ni || clamp(nj,0,m) != nj 
                || g[ni][nj] == '#' || parent[ni][nj] != 9
            ) continue;

            parent[ni][nj] = i;

            q.push({ni,nj});
        }
    }

    
    if (v.fi == -1) {
        cout << "NO";
        return 0;
    }

    vector<char> path;
    while ((v.fi != ai || v.se != aj) && parent[v.fi][v.se] != 9) {
        int dirPos = parent[v.fi][v.se];
        path.push_back(dirChar[dirPos]);
        v.fi -= dirs[dirPos].fi;
        v.se -= dirs[dirPos].se;
    }
    if (v.fi != ai || v.se != aj) cout << "NO";
    else {
        cout << "YES\n";
        cout << path.size() << '\n';
        for (int i = path.size()-1; i >= 0; i--) cout << path[i];
    }
    return 0;
}