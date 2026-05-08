#include <bits/stdc++.h>
using namespace std;

#define INF 1000000010

struct Point {
    int x, y;
};

int n;
vector<Point> v;

int main() {
    for (int t = 1; scanf("%d", &n) && (n!=0); ++t) {
        for (int i = 0; i < 2*n; i++) {
            string name;
            int x, y;
            cin >> name >> x >> y;
            v.push_back(Point{x,y});
        }
        int m = v.size();
        double dp[70000];
        int bitmask = static_cast<int>(pow(2,m))-1;
        dp[bitmask] = 0;
        
        for (int k = 0; k < n; k++) {
            double minval = INF;
            int minmask = bitmask;
            // Test all 2 bits pairs
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (i==j ||
                    ~bitmask & (1 << i) || ~bitmask & (1 << j))
                        continue;
    
                    // Set bits i, j to 0
                    int newmask = bitmask & ~(1 << i | 1 << j);
                    Point p1 = v[i];
                    Point p2 = v[j];
                    double dist = sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
    
                    dp[newmask] = dp[bitmask] + dist;
                    if (dp[newmask] < minval) {
                        minval = dp[newmask];
                        minmask = newmask;
                    }
                }
            }
            bitmask = minmask;
        }

        printf("Case %d: %llf\n", t, dp[0]);
    }

    return 0;
}
