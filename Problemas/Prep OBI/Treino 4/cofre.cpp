#include <bits/stdc++.h>
using namespace std;

int n, m;
int cofre[100001];
int prefSum[10][100001];
int counter[10];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", cofre+i);
    }
    for (int x = 0; x <= 9; x++) {
        // printf("%d: ", x);
        for (int i = 1; i <= n; i++) {
            prefSum[x][i] = prefSum[x][i-1] + (cofre[i] == x ? 1 : 0);
            // printf("%d ", prefSum[x][i]);
        }
        // printf("\n");
    }

    int pos;
    scanf("%d", &pos);
    counter[cofre[pos]]++;
    
    for (int i = 1; i < m; i++) {
        int newpos;
        scanf("%d", &newpos);
        for (int x = 0; x <= 9; x++) {
            int val;
            if (pos <= newpos)
                val = prefSum[x][newpos] - prefSum[x][pos];
            else
                val = prefSum[x][pos-1] - prefSum[x][newpos-1];
            
                counter[x] += val;
            // printf("counted %dx of %d in %d - %d\n", val, x, pos, newpos);
        }
        pos = newpos;
        // printf("\n");
    }
    for (int x = 0; x <= 9; x++) {
        printf("%d ", counter[x]);
    }

    return 0;
}

/*
prefSum
1 1 2 2 2 3 3 4 4 4 5

*/