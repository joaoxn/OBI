// Accepted
#include <bits/stdc++.h>
using namespace std;

int n;
bool dir[100];
string s;

int main() {
    cin >> n;
    cin >> s;
    string temp;
    cin >> temp >> temp;
    for (int i = 0; i < n; i++) {
        if (s[i*5] == '.') dir[i] = true;
        // printf("%d ", dir[i]);
    }
    
    int halfcost = 0;
    for (int i = 0; i < n/2; i++) {
        halfcost += dir[i];
    }
    for (int i = n/2; i < n; i++) {
        halfcost += !dir[i];
    }
    // printf("\n%d\n", halfcost);
    halfcost = min(halfcost, n-halfcost);

    int evencost = 0;
    for (int i = 0; i < n; i++) {
        if (i%2==0) {
            evencost += dir[i];
        } else {
            evencost += !dir[i];
        }
    }
    // printf("%d\n", evencost);
    evencost = min(evencost,n-evencost);
    // printf("%d %d\n", halfcost, evencost);
    printf("%d\n", min(halfcost,evencost));
}

/*
1 0 0 1 1 1 0 0


*/