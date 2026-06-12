#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define debugln(args...) debug(args); printf("\n")
#define fi first
#define se second

int n;
pair<int,int> p[2001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    int sol = -1;
    for (int i = 0; i < n; i++) {
        debugln("start: %d", i);
        auto curr = i;
        int last_dist = INT_MAX;
        int barracas = 1;
        while (true) {
            int maxd = -1;
            int maxj = -1;
            for (int j = 0; j < n; j++) {
                if (curr == j) continue;

                int dist = pow(p[i].fi-p[j].fi,2)+pow(p[i].se-p[j].se,2);
                if (dist > maxd) {
                    maxd = dist;
                    maxj = j;
                }
            }
            debugln("longe=%d", maxj);
            if (maxd == -1 || maxd >= last_dist) break;
            curr = maxj;
            last_dist = maxd;
            barracas++;
        }
        if (barracas > sol) sol = barracas;
    }

    cout << sol << '\n';
}