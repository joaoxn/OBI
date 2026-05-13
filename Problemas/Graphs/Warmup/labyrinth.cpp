#include <bits/stdc++.h>
using namespace std;

int n, m;

struct coord {
    int i, j;
    bool inBounds() {
        return (0 <= i && i < n) && (0 <= j && j < m);
    }
    coord operator +(const coord &other) const {
        return coord{i+other.i, j+other.j};
    }
    void operator +=(const coord &other) {
        i += other.i;
        j += other.j;
    }
    bool operator ==(const coord &other) const {
        return i == other.i && j == other.j;
    }
    bool operator !=(const coord &other) const {
        return !(*this == other);
    }
};

coord directions[] = {{-1,0},{0,1},{1,0},{0,-1}};
char dirchar[]     = {'U', 'R', 'D', 'L'};

int main() {
    scanf("%d %d", &n, &m);
    char mat[n][m];
    int ai, aj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);
            if (mat[i][j] == 'A') {
                ai = i;
                aj = j;
            }
        }
    }
    // printf("a{%d,%d}\n", ai,aj);
    queue<coord> q;
    q.push({ai,aj});
    int source[n][m];
    memset(source, -1, sizeof source);
    int bi, bj;
    while (!q.empty()) {
        coord v = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            coord next = v + directions[k];
            int i = next.i;
            int j = next.j;
            // printf("{%d,%d}: %c\n", i,j,mat[i][j]);
            if (!next.inBounds() || source[i][j] != -1 
            || mat[i][j] != '.' && mat[i][j] != 'B')
                continue;
            
            source[i][j] = k;
            if (mat[i][j] == 'B') {
                bi = i;
                bj = j;
                goto yes;
            }
            q.push(next);
        }
    }
    printf("NO\n");
    return 0;
    yes:
    printf("YES\n");
    vector<char> path;
    coord curr = {bi,bj};
    while (curr != coord{ai,aj} && curr.inBounds()) {
        int dir = source[curr.i][curr.j];
        path.push_back(dirchar[dir]);

        int oppdir = (dir + 2) % 4;
        curr += directions[oppdir];
    }
    printf("%d\n", path.size());
    for (int i = path.size()-1; i >= 0; --i) {
        printf("%c", path[i]);
    }
    printf("\n");

    return 0;
}