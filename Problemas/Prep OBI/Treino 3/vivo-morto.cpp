#include <bits/stdc++.h>
using namespace std;

int p, r;
list<int> l;

int main() {
    for (int t = 1; scanf("%d %d", &p, &r) && (p!=0 || r!=0); ++t) {
        l.clear();
        printf("Teste %d\n", t);

        for (int i = 0; i < p; ++i) {
            int x;
            cin >> x;
            l.push_back(x);
        }
        for (int i = 0; i < r; ++i) {
            int n, move;
            cin >> n >> move;

            for (auto it = l.begin(); it != l.end();) {
                int xMove;
                cin >> xMove;
                if (xMove != move) {
                    it = l.erase(it);
                } else ++it;
            }
        }
        printf("%d\n\n", l.front());
    }

    return 0;
}

/*
2 2
2 1
2 1 1 1
2 1 1 0
5 4
3 2 1 4 5
5 1 1 1 1 1 1
5 0 0 1 0 1 0
3 0 0 1 0
2 1 0 1
0 0

*/