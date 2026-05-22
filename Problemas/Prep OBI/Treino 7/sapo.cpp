// 100/100 - https://judge.beecrowd.com/pt/problems/view/2392
#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[120];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; // ax + b
		scanf("%d %d", &b, &a);
		for (int j = (b-1)%a; j < n; j+=a) {
			v[j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", v[i]);
	}

    return 0;
}