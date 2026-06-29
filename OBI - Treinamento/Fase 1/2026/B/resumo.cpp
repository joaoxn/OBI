// 100/100

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //printf(args)

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    int resumo[10];
    memset(resumo, -1, sizeof resumo);
    
    for (int i = 0; n >= 1; i++) {
        resumo[i] = n%10;
        n /= 10;
    }

    int k = 0;
    for (; k < 10 && resumo[k] != -1; k++) {}

    for (int i = 0; i*2 < k; i++) {
        int j = k - i-1;
        int temp = resumo[i];
        resumo[i] = resumo[j];
        resumo[j] = temp;
    }

    int c;
    for (c = 0; c < 1000; c++) {
        int novo[3] = {0,0,0};
        for (int i = 0; i < 10; i++) {
            if (resumo[i] == -1) continue;
            novo[0]++;
            if (resumo[i]%2==0) novo[2]++;
            else novo[1]++;
        }

        debug("\n");
        bool igual = novo[0] == 3;
        for (int i = 0; i < 3; i++) {
            debug("novo[%d]=%d\n", i, novo[i]);
            debug("resu[%d]=%d\n", i, resumo[i]);
            if (novo[i] != resumo[i]) igual = false;
        }

        memset(resumo, -1, sizeof resumo);
        for (int i = 0; i < 3; i++) {
            resumo[i] = novo[i];
            debug("%d",resumo[i]);
        }

        if (igual) break;
    }
    cout << c;
    
    return 0;
}