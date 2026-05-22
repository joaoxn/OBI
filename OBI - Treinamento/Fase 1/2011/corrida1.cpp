// 100/100 - https://judge.beecrowd.com/pt/problems/view/2394
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    pair<int,int> scores[n];
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            sum += x;
        }
        scores[i-1] = {sum, i};
    }
    
    sort(scores, scores+n);
    printf("%d\n", scores[0].second);

    return 0;
}