//TODO: Resolver (usando DP)

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define debugln(args...) debug(args); debug("\n")
#define fi first
#define se second

int n;
pair<int,int> p[2001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    p[0] = {0,0};

    int i = 0;
    int last_dist = INT_MAX;
    int barracas = 0;
    while (true) {
        int maxd = -1;
        int maxj = -1;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int dist = pow(p[i].fi-p[j].fi,2)+pow(p[i].se-p[j].se,2);
            debugln("%d (%d,%d)-(%d,%d)=%d", j, p[i].fi,p[i].se, p[j].fi,p[j].se, dist);
            if (dist > maxd && dist < last_dist) {
                maxd = dist;
                maxj = j;
            }
        }
        debugln("longe=%d", maxj);
        if (maxd == -1) break;
        i = maxj;
        last_dist = maxd;
        barracas++;
    }

    cout << barracas << '\n';
}