// https://judge.beecrowd.com/pt/problems/view/2919
// ! WA (wrong logic/algorithm used)
// Fails when last element is not on LIS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> v;
vector<int> dp;
vector<int> e; // indexes of LIS
int pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        pos = n;
        v.clear(); v.resize(n);
        dp.clear(); dp.resize(n);
        e.clear(); e.resize(n);
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        
    }
}

/*

SRTBOT
Subprobs: 
L(i) = LIS(A[i:]); E(i) = v[j] where j is first element of LIS(A[i:])

Relate: 
if A[i] < E(i): L(i) = 1 + L(i+1)
else: 
    k = first x in LIS(A[i:]) where A[i] < x //* Binary Search
    if (L(i+1) == L(k) && A[i] >(=) k): 
        choose 1+L(k) path
    else: 
        L(i) = max(L(i+1), 1+L(k))

Topo: for i = [n-1,0]: solve L(i)
Base: L(n-1) = 1
Original: L(0)
Time: O(nlogn)

*/
