#include <bits/stdc++.h>
using namespace std;

int n;
const int maxcrivo = 10e6+1;
bool crivo[maxcrivo];
vector<int> primos;

int main() {
    memset(crivo, true, sizeof crivo);
    for (int i = 2; i*i < maxcrivo; ++i) {
        for (int j = 2*i; j*j < maxcrivo; j += i) {
            crivo[j] = false;
        }
    }
    for (int i = 2; i*i < maxcrivo; ++i) {
        if (crivo[i]) primos.push_back(i);
    }
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int divisors = 0;
        for (int primo : primos) {
            if (x % primo == 0) {
                ++divisors;
                if (divisors > 3) break;
            }
        }
        printf(divisors == 3 ? "YES\n" : "NO\n");
    }

    return 0;
}