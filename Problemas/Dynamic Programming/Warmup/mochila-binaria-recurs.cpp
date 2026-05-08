#include <bits/stdc++.h>
using namespace std;

int n, c;
int w[1000], v[1000];
int dp[1000][1000];
bool flag[1000][1000];

int solve(int i, int cap) {
    if (i == 0) {
        return cap >= w[i] ? v[i] : 0;
    }
    if (flag[i][cap]) return dp[i][cap];

    int s1 = solve(i-1, cap);
    int s2 = solve(i-1,cap-w[i]) + v[i];
    if (cap-w[i] < 0) s2 = s1;

    flag[i][cap] = true;
    dp[i][cap] = max(s1,s2);
    return dp[i][cap];
}

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", w+i, v+i);
    }

    printf("%d\n", solve(n-1,c));

    return 0;
}

/*
Subproblemas: item, capacidade = valor

4 7
2 10
1 7
6 25
5 24

*/