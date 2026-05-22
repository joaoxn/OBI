// Subtarefas: 2/10
#include <bits/stdc++.h>
using namespace std;

int n;
int ops[10];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        char op;
        scanf(" %d %c", &x, &op);
        ops[x] += (op=='*'?1:-1);
    }
    double calc = 1;
    for (int i = 2; i <= 9; i++) {
        while (ops[i] != 0) {
            if (ops[i] > 0) {
                calc *= i;
                ops[i]--;
            }
            else {
                calc /= i;
                ops[i]++;
            }
        }
    }
    printf("%.0f\n", round(calc));

    return 0;
}