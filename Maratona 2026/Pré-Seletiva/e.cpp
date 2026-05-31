// Wrong Answer
// Algoritmo de Kadane

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[100100];
int a1[100100]; // 1o valor inalterado
int a2[100100]; // 1o valor alterado

int32_t main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", a+i);
        a1[i] = i%2==0 ? a[i] : -a[i];
        a2[i] = -a1[i];
    }

    vector<int> g1;
    vector<int> g2;
    for (int i = 0; i < n-1; i++) {
        if (i%2 == 0)
            g1.push_back(a1[i]+a1[i+1]);
        else
            g2.push_back(a2[i]+a2[i+1]);
    }
    if ((n-1)%2==0) g1.push_back(a2[n-1]);
    else g2.push_back(a1[n-1]);

    long long best = 0;
    long long sum = 0;
    for (int i = 0; i < g1.size(); i++) {
        // printf("%d ", g1[i]);
        if (sum + g1[i] <= 0) {
            best = max(best,sum);
            sum = 0;
            continue;
        }
        sum += g1[i];
    }
    long long best1 = max(best,sum);
    // printf("\n");
    best = 0;
    sum = 0;
    for (int i = 0; i < g2.size(); i++) {
        // printf("%d ", g2[i]);
        if (sum + g2[i] <= 0) {
            best = max(best,sum);
            sum = 0;
            continue;
        }
        sum += g2[i];
    }
    // printf("\n");
    long long best2 = max(best,sum);
    printf("%lld\n", max(best1, best2));
}