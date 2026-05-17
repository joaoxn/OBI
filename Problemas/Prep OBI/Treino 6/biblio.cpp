/*
Programação Dinâmica
Subproblema: Subárvore com raiz de nível maior que o atual

Bottom-up: Resolver para pai de cada folha, então resolver para pai destes.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int freq[60];



int main() {
    for (int t = 1; scanf("%d", &n) > 0 && (n!=0); ++t) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", freq+i);
        }

        int l=0, r=n-1;
        while (l < r) {
            int mid = (l+r)/2;
            
        }
    }

    return 0;
}

/*
arvore = [0, 1,2, 3,4,5,6, 7,8,9,10,11,12,13,14]
*/