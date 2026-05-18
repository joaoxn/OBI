#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int val(int c) {
    return c-'0';
}

int main() {
    cin >> t;
    for (int _t = 0; _t < t; ++_t) {
        cin >> s;
        int n = s.size();
        int impares[n];
        int resto2[n];
        memset(impares, 0, sizeof impares);
        memset(resto2, 0, sizeof resto2);
        impares[0] = val(s[0])%2==1;
        resto2[0] = val(s[0])%4==2;
        printf("%d %d\n", impares[0],resto2[0]);
        
        for (int i = 1; i < n; ++i) {
            int v = val(s[i]);
            impares[i] = impares[i-1] + (v%2==1);
            resto2[i] = resto2[i-1] + (v%4==2);
            printf("%d %d\n", impares[i],resto2[i]);
        }
        
        int count = 0;
        int dp[n];
        memset(dp, INT_MAX, sizeof dp);
        
        for (int i = 0; i < n; ++i) {
            int v = s[i] - '0';
            if (v % 4 == 0) {
                ++count;
                continue;
            }
            int minv = min(impares[i],resto2[i]);
            printf("i:%d;min(%d,%d)=%d\n",i,impares[i],resto2[i],minv);
            for (int j = 0; j < i; ++j) {
                if (impares[j]==0 || resto2[j]==0) continue;
                int impar = impares[i]-impares[j];
                int r2 = resto2[i]-resto2[j];
                if (r2==0 || impar==0) continue;
                
                minv = min(minv,min(impar,r2)+dp[j]);
                printf("j:%d;%d+%d;minv=%d\n",j,min(impar,r2),dp[j],minv);
            }
            dp[i] = minv;
            printf("dp[%d]=%d\n",i,dp[i]);
        }
        printf("%d\n", count+dp[n-1]);

    }

    return 0;
}

/*
Teste de divisibilidade por 4
4 8 12 16 20 24 28 32 36 40
14
se dezena é impar, unidade%4==2
se dezena é par, unidade%4==0

322222

*/