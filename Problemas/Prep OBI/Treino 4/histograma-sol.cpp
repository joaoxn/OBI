#include <bits/stdc++.h>
using namespace std;

#define LIMIT 100000

int n;
int h[LIMIT];
stack<int> s;

int main() {
    for (int t = 1; scanf("%d", &n) > 0 && (n!=0); ++t) {

        scanf("%d", h);
        s.push(0);
        // printf("Push: %d\n", s.top());
        int max = 0;
        for (int i = 1; i <= n; i++) {
            if (i != n) scanf("%d", h+i);
            // printf("Push: %d\n", h[i]);
            while (!s.empty() && h[s.top()] > h[i]) {
                int height = h[s.top()];
                s.pop();
                int len = s.empty() ? i : i - s.top() - 1;
                int area = height*len;
                // printf("Removed %d with area %d\n", s.top(), area);
                if (area > max) max = area;
            }
            if (i != n) s.push(i);
        }

        printf("%d\n", max);
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
