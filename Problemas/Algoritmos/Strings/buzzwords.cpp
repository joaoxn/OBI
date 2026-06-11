#include <bits/stdc++.h>
using namespace std;

string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string full_str;
    while (getline(cin, full_str) && !full_str.empty()) {
        str = "";
        for (char c : full_str) {
            if (c != ' ') str.push_back(c);
        }
        int n = str.size();

        for (int l = 1; l <= n; l++) {
            //cout << "l=" << l << '\n';
            map<string,int> counts;
            for (int i = 0; i <= n-l; i++) {
                string substr = str.substr(i,l);
                counts[substr]++;
                //cout << substr << "++ = " << counts[substr] << '\n';
            }
            int maxv = 0;
            for (const auto& [key,val] : counts) {
                //cout << key << " - " << val << '\n';
                if (val > maxv) maxv = val;
            }
            if (maxv <= 1) break;
            cout << maxv << '\n';
        }
        cout << '\n';
    }
    

    return 0;
}