#include <bits/stdc++.h>
using namespace std;

int n, plrs;
bool descarte[14];

struct Pilha {
    int top;
    int size;
};

int main() {
    for (int t = 1; scanf("%d %d",&n,&plrs) && (n!=0 || plrs!=0); ++t) {
        memset(descarte, false, sizeof descarte);
        Pilha pilhas[plrs+1];
        for (int i = 1; i <= plrs; i++) {
            pilhas[i] = Pilha{0,0};
        }
        int plr = 1;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);

            if (descarte[x]) {
                pilhas[plr].top = x;
                pilhas[plr].size += 2;
                descarte[x] = false;
                continue;
            }

            bool stole = false;
            for (int j = 1; j <= plrs; j++) {
                if (j == plr) continue;
                if (pilhas[j].top == x) {
                    stole = true;
                    pilhas[plr].top = x;
                    pilhas[plr].size += pilhas[j].size + 1;
                    pilhas[j].top = 0;
                    pilhas[j].size = 0;
                }
            }
            if (stole) 
                continue;

            if (pilhas[plr].top == x) {
                pilhas[plr].size++;
                continue;
            }

            descarte[x] = true;
            ++plr;
            plr %= plrs;
            if (plr == 0) plr = plrs;
        }

        int max = 0;
        for (int i = 1; i <= plrs; i++) {
            if (pilhas[i].size > max) max = pilhas[i].size;
        }
        printf("%d", max);
        for (int i = 1; i <= plrs; i++) {
            if (pilhas[i].size == max) {
                printf(" %d", i);
            }
        }
        printf("\n");
    }
}

/*
4 2
10 7 2 5
6 3
1 2 1 2 1 2
8 2
3 3 1 1 2 3 4 5
0 0

*/