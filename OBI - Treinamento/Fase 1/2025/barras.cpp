#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    
    int max = 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }

    for (int i = max; i > 0; --i) {
        for (int j = 0; j < n; ++j) {
            printf(arr[j] >= i ? "1 " : "0 ");
        }
        printf("\n");
    }

    return 0;
}