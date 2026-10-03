// https://judge.beecrowd.com/pt/runs/code/50148787
// 100/100

#include <bits/stdc++.h>
using namespace std;

#define IGN if(0) 
#define fi first
#define se second
typedef pair<int,int> pii;

int n, logn;
vector<pii> pairs;
vector<vector<int>> up;
vector<int> dist;

void setDist(int u) {
	if (up[u][0] == u) return;

	int v = up[u][0];
	if (dist[v] == 0)
		setDist(v);
	
	dist[u] = dist[v]+1;
}

int lca(int a, int b) {
	if (dist[a] < dist[b]) swap(a,b);
	int k = dist[a] - dist[b];
	
	for (int j = logn-1; k > 0 && j >= 0; j--) {
		if (k & 1<<j) {
			a = up[a][j];
			k -= 1<<j;
		}
	}

	for (int j = logn-1; j >= 0; j--) {
		int aj = up[a][j];
		int bj = up[b][j];
		if (aj != bj) {
			a = aj;
			b = bj;
		}
	}
	if (a == b) return a;
	else return up[a][0];
}

int main(){

	cin >> n;
	logn = 0;
	for (int i = 1; i < n; i*=2) logn++;
	pairs.resize(n/2+1);
	up.resize(n+1,vector<int>(logn));
	dist.resize(n+1);
	
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (pairs[x].fi == 0) 
			pairs[x].fi = i;
		else pairs[x].se = i;
	}
	
	up[1][0] = 1;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a,b);
		up[b][0] = a;
	}
	
	for (int i = 2; i <= n; i++) setDist(i);
	
	for (int j = 1; j < logn; j++) {
		for (int i = 1; i <= n; i++) {
			up[i][j] = up[up[i][j-1]][j-1];
		}
	}
	
	int total = 0;
	for (pii p : pairs) {
		int a = p.fi, b = p.se;
		int c = lca(a,b);
		
		total += dist[a]-dist[c];
		total += dist[b]-dist[c];
	}
	cout << total << '\n';
    return 0;
}
