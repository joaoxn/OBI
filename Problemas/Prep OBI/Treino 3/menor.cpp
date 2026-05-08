#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> s;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "PUSH") {
            int x;
            cin >> x;
            s.push(x);
        } else if (cmd == "POP") {
            if (s.empty()) {
                printf("EMPTY\n");
            } else {
                s.pop();
                
            }
        } else {
            printf("%d\n", s.top());
        }
    }

    return 0;
}
