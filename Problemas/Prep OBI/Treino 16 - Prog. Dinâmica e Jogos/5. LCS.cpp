// https://atcoder.jp/contests/dp/tasks/dp_f?lang=en

#include <bits/stdc++.h>
using namespace std;

#define IGN if (0)
#define INF LLONG_MAX
typedef long long ll;
typedef pair<int,int> pii;

string s, t;
int n, m;
vector<vector<int>> dp;
vector<vector<pii>> trace;

void setTrace(int i, int j, int k, int l) {
    if (s[k] == t[l]) trace[i][j] = {k,l};
    else trace[i][j] = trace[k][l];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    n = s.size(); m = t.size();
    dp.resize(n+1, vector<int>(m+1));
    trace.resize(n+1, vector<pii>(m+1,{-1,-1}));
    
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (s[i] == t[j]) {
                dp[i][j] = 1+dp[i+1][j+1];
                setTrace(i,j,i+1,j+1);
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                
                if (dp[i+1][j] >= dp[i][j+1]) setTrace(i,j,i+1,j);
                else setTrace(i,j,i,j+1);
            }
        }
    }

    int sz = dp[0][0];

    string str;
    if (s[0] == t[0]) str.push_back(s[0]);
    pii next = trace[0][0];
    while (next.first != -1 && next.second != -1) {
        str.push_back(s[next.first]);
        next = trace[next.first][next.second];
    }
    for (int i = 0; i < sz; i++) {
        cout << str[i];
    }
}

/*

SRTBOT
Subproblems:
dp[i][j] = LCS(s[i:],t[j:])

Relate:
if (s[i] == t[j]): dp[i][j] = 1 + dp[i+1][j+1]
else:
    dp[i][j] = max(dp[i+1][j], dp[i][j+1])

Topo: for (i = [0,n]): for (j = [0,m])

Base: dp[s.size()][t.size()] = 0
Origin: dp[0][0]
Time Complexity: O(n²) subproblems * O(1) nonrecursive

*/