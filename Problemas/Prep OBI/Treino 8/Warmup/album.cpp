#include <bits/stdc++.h>
using namespace std;

int x, y;
int l1, h1, l2, h2;

bool canFit(int l1, int h1, int l2, int h2) {
    int bl = max(l1,l2);
    int bh = max(h1,h2);
    int tl = l1+l2;
    int th = h1+h2;

    return (bl <= x && th <= y) || (tl <= x && bh <= y);
}

int main() {
    scanf("%d %d", &x, &y);
    scanf("%d %d %d %d", &l1, &h1, &l2, &h2);

    if (canFit(l1,h1,l2,h2) 
    || canFit(l1,h1,h2,l2) 
    || canFit(h1,l1,l2,h2) 
    || canFit(h1,l1,h2,l2)) {
        printf("S");
    } else {
        printf("N");
    }
    printf("\n");
    
    return 0;
}