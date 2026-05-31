// 100/100 - https://judge.beecrowd.com/pt/problems/view/2419
// Contagem de células de terra que possuem vizinho mar
#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[1000][1000];

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" ");
		for (int j = 0; j < m; j++) {
			scanf("%c", &mat[i][j]);
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != '#') continue;
            // Encontrar vizinhos utilizando for com k e l
			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					// Exclui vizinhos de canto e a própria célula: (±1,±1) ou (0,0) 
                    if (abs(k) == abs(l)) 
						continue;
					if (i+k < 0 || i+k >= n || j+l < 0 || j+l >= m
					|| mat[i+k][j+l] == '.') {
						count++;
						goto nextj;
					}
				}
			}
			nextj:
			printf("");
		}
	}
	printf("%d\n", count);

    return 0;
}