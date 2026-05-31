// 100/100 - https://judge.beecrowd.com/pt/problems/view/2424
// Verificar se ponto está dentro de um retângulo predeterminado
#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    scanf("%d %d", &x, &y);
    
    printf(0 <= x && x <= 432 && 0 <= y && y <= 468 ? "dentro" : "fora");
    printf("\n");

    return 0;
}