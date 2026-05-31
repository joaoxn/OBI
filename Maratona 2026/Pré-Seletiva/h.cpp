// Accepted
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> boxes[100];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        boxes[i].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &boxes[i][j]);
        }
    }
    vector<vector<int>> sol;
    while (sol.size() < n) {
        int min = INT_MAX;
        int min_i = 0;
        for (int i = 0; i < n; i++) {
            if (boxes[i][0] == INT_MAX) continue;
            bool accept = false;
            for (int j = 1; boxes[i][j-1] == min; j++) {
                // printf("comp box[%d][%d] box[%d][%d]\n", min_i, j, i, j);
                if (j >= boxes[min_i].size()) break;
                if (j >= boxes[i].size()) {
                    accept = true;
                    break;
                }
                if (boxes[i][j] < boxes[min_i][j]) {
                    accept = true;
                    break;
                }
            }
            if (boxes[i][0] < min || accept) {
                // printf("min %d\n", i);
                min = boxes[i][0];
                min_i = i;
            }
        }
        // printf("select %d\n", min_i);
        sol.push_back(boxes[min_i]);
        boxes[min_i][0] = INT_MAX;
    }

    int last = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sol[i].size(); j++) {
            // printf("%d ", sol[i][j]);
            if (sol[i][j] < last) {
                printf("NO\n");
                return 0;
            }
            last = sol[i][j];
        }
    }
    printf("YES\n");
    return 0;
}

/*
2
2 3 5
2 3 3

4
2 3 5
1 3
2 3 4
1 3
*/