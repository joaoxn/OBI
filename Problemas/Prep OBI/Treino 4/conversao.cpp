#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        string x;
        string nomeBase;
        cin >> x >> nomeBase;
        int base = 0;
        if (nomeBase == "bin") 
            base = 2;
        else if (nomeBase == "dec")
            base = 10;
        else base = 16;
        
        int decimal = stoi(x, nullptr, base);

        printf("Case %d:\n", i);
        if (base != 10) {
            cout << decimal << " dec\n";
        }
        if (base != 16) {
            cout << hex << decimal << dec << " hex\n";
        }
        if (base != 2) {
            int bits = decimal;
            vector<int> ans;
            while (bits > 0) {
                ans.push_back(bits & 1);
                bits >>= 1;
            }
            for (int i = ans.size()-1; i >= 0; i--) {
                printf("%d", ans[i]);
            }
            printf(" bin\n");
        }
        printf("\n");
    }

    return 0;
}