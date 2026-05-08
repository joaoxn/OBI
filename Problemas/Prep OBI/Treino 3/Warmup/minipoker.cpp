#include <bits/stdc++.h>
using namespace std;

int n;
int c[5], counts[14];

int main() {
    scanf("%d", &n);
    for (int t = 1; t <= n; t++) {
        printf("Teste %d\n", t);
        
        scanf("%d %d %d %d %d", c, c+1, c+2, c+3, c+4);
        sort(c,c+5);
        
        bool sequencia = true;
        
        memset(counts, 0, sizeof counts);
        for (int i = 0; i < 5; i++) 
            ++counts[c[i]];

        for (int i = 1; i < 5; i++) {
            if (c[i] != c[0] + i) {
                sequencia = false;
            }
        }
        if (sequencia) {
            printf("%d\n\n", c[0]+200);
            continue;
        }

        int quadra=0, trinca=0, par=0, par2=0;
        for (int i = 1; i <= 13; i++) {
            if (counts[i] >= 4)
                quadra = i;
            else if (counts[i] == 3)
                trinca = i;
            else if (par && counts[i] == 2)
                par2 = i;
            else if (counts[i] == 2)
                par = i;
        }
        
        int score = 0;
        if (quadra) {
            score = quadra+180;
        } else if (trinca && par) {
            score = trinca+160;
        } else if (trinca) {
            score = trinca+140;
        } else if (par2) {
            score = 3*par2+2*par+20;
        } else if (par) {
            score = par;
        }
        printf("%d\n\n", score);
    }

    return 0;
}

/*
12
12 3 10 3 12
1 2 3 5 4
1 1 2 2 3
6 4 3 2 1
1 1 1 1 4
10 9 8 11 12
1 1 1 10 1
10 4 4 10 4
2 3 2 2 12
12 7 122 8 7
12 13 5 8 13
10 1 2 4 6 11

->
62
201
28
0
181
208
181
164
142
70
13
0

*/