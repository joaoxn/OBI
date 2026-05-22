// 100/100 - https://judge.beecrowd.com/pt/problems/view/2407
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int mat[1001][1001];
set<int> nums;

int32_t main() {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            sum += mat[i][j];
            if (nums.find(mat[i][j]) != nums.end()) {
                printf("0\n");
                return 0;
            }
            nums.insert(mat[i][j]);
        }
    }
    if (sum % n != 0) {
        printf("0\n");
        return 0;
    }
    int magicSum = sum/n;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += mat[i][j];
        }
        if (sum != magicSum) {
            printf("0\n");
            return 0;
        }
    }
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[i][j];
        }
        if (sum != magicSum) {
            printf("0\n");
            return 0;
        }
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        int j1 = i;
        int j2 = n-i-1;
        sum1 += mat[i][j1];
        sum2 += mat[i][j2];
    }
    if (sum1 != magicSum || sum2 != magicSum) {
        printf("0\n");
        return 0;
    }

    printf("%lld\n", magicSum);

    return 0;
}