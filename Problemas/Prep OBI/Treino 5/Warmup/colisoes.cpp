#include <iostream>
using namespace std;

int x0, y0, x1, y1;
int x2, y2, x3, y3;

int main() {
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    scanf("%d %d %d %d", &x2, &y2, &x3, &y3);
    
    bool nao_colidiu = x1 < x2 || x3 < x0 || y1 < y2 || y3 < y0;
    
    printf("%d\n", !nao_colidiu);

    return 0;
}