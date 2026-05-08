#include <bits/stdc++.h>
using namespace std;

#define LIMIT 100001

int n;
int h[LIMIT];
stack<int> s;

int main() {
    for (int t = 1; scanf("%d", &n) > 0 && (n!=0); ++t) {
        scanf("%d", h);
        s.push(0);

        long long maxval = 0;
        for (int i = 1; i <= n; i++) {
            if (i < n) scanf("%d", h+i);
            while (!s.empty() && (i == n || h[s.top()] > h[i])) {
                int height = h[s.top()];
                s.pop();
                int length = s.empty() ? i : i - s.top() - 1;
                maxval = max(maxval, (long long)height*length);
            }
            if (i < n) s.push(i);
        }
        printf("%lld\n", maxval);
    }

    return 0;
}

/*
11  10 1 11 10 1 6 9 5 7 5 2
-> 25

1 2 3 4 5
5 4 3 2 1
-> 9

*/
