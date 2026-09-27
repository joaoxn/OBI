// https://olimpiada.ic.unicamp.br/pratique/ps/2017/f3/codigo/
// 60/100

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n;
vector<string> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    s.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i < n; i++) {
        int maxpref = 0, maxsuff = 0;

        for (int j = 0; j < i; j++) {
            int sz = min(s[i].size(),s[j].size());
            int pref = 0, suff = 0;
            for (int len = sz; len > 0; len--) {
                bool isPref = pref==0, isSuff = suff==0;
                if (!isPref && !isSuff) break;

                for (int k = 0; k < len && (isPref || isSuff); k++) {
                    int l = sz-len+k;
                    if (isPref && s[i][k] != s[j][l]) isPref = false;
                    if (isSuff && s[i][l] != s[j][k]) isSuff = false;
                }
                if (isPref) pref = len;
                if (isSuff) suff = len;
            }

            if (pref > maxpref) {
                maxpref = pref;
            }
            if (suff > maxsuff) {
                maxsuff = suff;
            }
        }
        if (maxpref + maxsuff >= s[i].size()) {
            cout << s[i];
            return 0;
        }
    }

    // for (int i = 1; i < n; i++) {
    //     int maxpref = 0, maxsuff = 0;
    //     int prefj = -1, suffj = -1;
    //     for (int j = 0; j < i; j++) {
    //         if (pref[i][j] > maxpref) {
    //             maxpref = pref[i][j];
    //             prefj = j;
    //         }
    //         if (suff[i][j] > maxsuff) {
    //             maxsuff = suff[i][j];
    //             suffj = j;
    //         }
    //     }

    //     if (false && maxpref + maxsuff >= s[i].size()) {
    //         cout << s[i];
    //         return 0;
    //     }
    // }

    cout << "ok";

    return 0;
}

/*
SRTBOT
ideia: guardar prefixo e sufixo que é substr de Si em cada Sj

Subproblem:
pref[i][j] = tamanho da maior substr começando no início de Si e acabando no fim de Sj
suff[i][j] = tamanho da maior substr começando no início de Sj e acabando no fim de Si

build pref and suff: iterate i,j e verif. em O(size) = O(1) (size = 10)
    O(n²)

Relate:
find j and k where pref[i][j]+suff[i][k] >= Si.size():

if exists: return Si
else: i++

Find: max(pref) and max(suff) - O(n) 

Tempo necessário: O(n²)

*/