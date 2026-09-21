// https://vjudge.net/problem/Kattis-paintings
// https://vjudge.net/contest/844995#problem/A

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)

int n, m, T;
vector<string> v;
vector<set<int>> h;

vector<int> st;
vector<bool> used;
int usedAmt, amt;
bool isBest;

void backtrack(int i) {
    if (isBest) st.push_back(i);
    used[i] = true;
    usedAmt++;
    if (usedAmt >= n) {
        amt++;
        isBest = false;
        used[i] = false;
        usedAmt--;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (used[j]) continue;
        if (h[j].find(i) != h[j].end()) continue;
        backtrack(j);
    }
    used[i] = false;
    usedAmt--;
    if (isBest) st.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T-- > 0) {
        cin >> n;
        v.resize(n);
        h.clear(); h.resize(n);
        used.clear(); used.resize(n);
        st.clear();
        usedAmt = 0;
        amt = 0;
        isBest = true;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            string a, b; cin >> a >> b;
            int ai, bi;
            for (int i = 0; i < n; i++) {
                if (v[i] == a) {
                    ai = i;
                } else if (v[i] == b) {
                    bi = i;
                }
            }
            h[ai].insert(bi);
            h[bi].insert(ai);
        }

        for (int i = 0; i < n; i++) {
            backtrack(i);
        }
        cout << amt << '\n';
        for (int i : st) cout << v[i] << ' ';
        cout << '\n';
    }

    return 0;
}