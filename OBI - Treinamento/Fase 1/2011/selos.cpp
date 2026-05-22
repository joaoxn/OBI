// 100/100 - https://judge.beecrowd.com/pt/problems/view/2402
#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
    scanf("%lld", &n);
    char sol = n%2==0 ? 'S':'N';
    for (long long i = 3; i*i <= n && sol == 'N'; i+=2) {
        if (n%i==0) sol = 'S';
    }
    printf("%c\n", sol);

    return 0;
}