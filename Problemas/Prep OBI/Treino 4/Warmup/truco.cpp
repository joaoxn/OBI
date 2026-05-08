#include <bits/stdc++.h>
using namespace std;

int n;
int a[3];
int b[3];
int aWins = 0, bWins = 0;

map<int, int> score = {
    {4,4},
    {5,5},
    {6,6},
    {7,7},
    {12,10},
    {11,11},
    {13,13},
    {1,21},
    {2,22},
    {3,23}
};

int main() {
    scanf("%d", &n);
    for (int r = 0; r < n; r++) {
        for (int i = 0; i < 3; i++) {
            scanf("%d", a+i);
            a[i] = score[a[i]];
        }
        for (int i = 0; i < 3; i++) {
            scanf("%d", b+i);
            b[i] = score[b[i]];
        }

        // sort(a,a+3,greater());
        // sort(b,b+3,greater());

        int ar=0, br=0;
        for (int i = 0; i < 3; i++) {
            if (b[i] > a[i])
                ++br;
            else ++ar;
        }
        if (br > ar)
            ++bWins;
        else ++aWins;
    }
    printf("%d %d\n", aWins, bWins);
}