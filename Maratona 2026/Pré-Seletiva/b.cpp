// Accepted
#include <bits/stdc++.h>
using namespace std;

string s;
long long v;
int bytes[4];

int main() {
    cin >> s >> v;
    for (int i = 0; i < 4; i++) {
        bytes[i] = v%256;
        v >>= 8;
    }
    long long res = 0;
    for (int i = 0; i < 4; i++) {
        res += static_cast<long long>(bytes[i]) << (8*(3-i));
        // printf("b[%d]=%d\n", i, bytes[i]);
    }
    printf("%lld\n", res);
}

/*
257 - 65536
*/