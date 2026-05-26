// 100/100 - https://judge.beecrowd.com/pt/problems/view/2398
#include <bits/stdc++.h>
using namespace std;

int n, k;
int mat[100][100];

int main() {
    scanf("%d %d", &n, &k);
    for (int it = 0; it < k; it++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int dist = abs(i-x)+abs(j-y);
                if (dist == d) {
                    mat[i][j]++;
                }
            }
        }
    }

    int xs = 0;
    pair<int,int> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == k) {
                xs++;
                x = {i,j};
            }
        }
    }
    if (xs == 1)
        printf("%d %d\n", x.first, x.second);
    else printf("-1 -1\n");

    return 0;
}