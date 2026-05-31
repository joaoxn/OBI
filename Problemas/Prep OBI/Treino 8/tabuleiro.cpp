// 100/100 - https://judge.beecrowd.com/pt/problems/view/2411
// Simulação com Matrizes
#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> mov[] = {
    {},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}
};// 0   1     2     3      4      5        6       7      8

int main() {
    scanf("%d", &n);
    int x=4,y=3;
    int i;
    for (i = 1; i <= n; i++) {
        int m;
        scanf("%d", &m);
        x += mov[m].first;
        y += mov[m].second;
        if (x == 1 && y == 3
        || x == 2 && y == 3
        || x == 2 && y == 5
        || x == 5 && y == 4) {
            i++;
            break;
        }
    }
    printf("%d\n", i-1);
}