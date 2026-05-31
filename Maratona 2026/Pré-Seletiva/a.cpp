// Accepted
#include <bits/stdc++.h>
using namespace std;

int T;
char a, b;

pair<int,int> moves[] = {{1,2}, {2,1}, {2,-1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf(" %c %c", &a, &b);
        int x = a-'a';
        int y = b-'1';

        int count = 0;
        for (auto move : moves) {
            int mx = x+move.first;
            int my = y+move.second;
            if (0 <= mx && mx < 8 && 0 <= my && my < 8) count++;
        }
        printf("%d\n", count);
    }
}