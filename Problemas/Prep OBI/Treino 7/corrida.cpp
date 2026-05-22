#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    pair<int,int> scores[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        scores[i] = {a+b, i};
    }
    
    sort(scores, scores+n);
    printf("%d\n%d\n%d\n", scores[0].second, scores[1].second, scores[2].second);

    return 0;
}