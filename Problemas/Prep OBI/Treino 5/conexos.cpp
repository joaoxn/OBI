#include <bits/stdc++.h>
using namespace std;

int n, v, e;

vector<vector<char>> grafo('z'+1);
char conexos['z'+1];

void dfs(char v, char group) {
    conexos[v] = group;
    for (char neighbor : grafo[v]) {
        if (conexos[neighbor] != 0) continue;
        dfs(neighbor, group);
    }
}

int main() {
    scanf("%d", &n);
    for (int t = 1; t <= n; ++t) {
        memset(conexos, 0, sizeof conexos);
        grafo.clear();
        
        printf("Case #%d:\n", t);
        scanf("%d %d", &v, &e);
        grafo.resize('a'+v);


        for (int i = 0; i < e; i++) {
            char x, y;
            scanf(" %c %c", &x, &y);
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }

        for (char i = 'a'; i < 'a'+v; ++i) {
            if (conexos[i] != 0) continue;
            dfs(i,i);
        }

        int components = 0;
        for (char i = 'a'; i < 'a'+v; ++i) {
            if (conexos[i] != i) continue;
            bool empty = true;
            for (char j = 'a'; j < 'a'+v; ++j) {
                if (conexos[j] != i) continue;
                empty = false;
                printf("%c,", j);
            }
            if (!empty) ++components;
            printf("\n");
        }
        printf("%d connected components\n\n", components);
    }

    return 0;
}