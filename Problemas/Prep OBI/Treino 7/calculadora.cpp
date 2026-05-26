// 100/100 - https://judge.beecrowd.com/pt/problems/view/2401
#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    long double calc = 1;
    for (int i = 0; i < n; i++) {
        int x;
        char op;
        scanf(" %d %c", &x, &op);
        if (op == '*')
            calc *= x;
        else calc /= x;
    }
    printf("%.0Lf\n", roundl(calc));

    return 0;
}

/*
Problema não exige otimização, 
porém variável de cálculo PRECISA ser long double

Otimizações possíveis:
Pensar em uma gigante fração: (a^x1*b^x2*...)/(e^x5*f^x6*...)
- Fatorar números para poder cortá-los
- Cortar números iguais no numerador e denominador
    Contar repetições de um número
- Realizar multiplicação e divisão ambos frequentemente, 
    para evitar atingir o limite numérico
*/