#include <bits/stdc++.h>
using namespace std;

int t;
char a[2000], b[2000];

int main() {
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        scanf("%s %s", a, b);
        if (strlen(a) > strlen(b)) {
            swap(a,b);
        }


    }

    return 0;
}

/*
5
FOOD
MONEY

ABC
AAA

ABCDE
FGH

ABCDE
CEA

ABCDE
CFFA

ABCDE
CE

<< 
4
2
5
4
3

*/