#include <stdio.h>

int n;

int main() {
    scanf("%d", &n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        int partes;
        scanf("%d", &partes);
        count += partes-1;
    }
    printf("%d\n", count);

    return 0;
}