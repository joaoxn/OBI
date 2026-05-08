#include <bits/stdc++.h>
using namespace std;

int n;
char mat[500][500];

map<char,pair<int,int>> dxdy = {
    {'V', {1,0}},
    {'<', {0,-1}},
    {'>', {0,1}},
    {'A', {-1,0}}
};

queue<pair<int,int>> q;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &mat[i][j]);
            pair<int,int> pos = dxdy[mat[i][j]];
            pos.first += i;
            pos.second += j;
            if (!(0 <= pos.first && pos.first < n) 
            || !(0 <= pos.second && pos.second < n)) {
                q.push({i,j});
            }
        }
    }

    pair<int,int> diffs[4] = {{-1,0},{0,-1},{0,1},{1,0}};

    int amt = 0;
    while (!q.empty()) {
        ++amt;
        pair<int,int> pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int,int> neighPos = pos;
            neighPos.first += diffs[i].first;
            neighPos.second += diffs[i].second;
            
            if (!(0 <= neighPos.first && neighPos.first < n) 
            || !(0 <= neighPos.second && neighPos.second < n))
                continue;
            
            pair<int,int> diff = dxdy[mat[neighPos.first][neighPos.second]];
            if (neighPos.first + diff.first == pos.first 
                && neighPos.second + diff.second == pos.second) {
                    q.push(neighPos);
                }
        }
    }
    printf("%d\n", n*n-amt);

    return 0;
}