#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>

using namespace std;

string compute(int n, string order) {
    stringstream ss(order);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        ss >> num;
        v.push_back(num);
    }

    stack<int> s;
    int i = 0;
    for (int c = 1; c <= n && i < n; c++) {
        s.push(c);
        while (!s.empty() && s.top() == v[i]) {
            s.pop();
            i++;
        }
    }
    return s.empty() ? "Yes" : "No";
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        string _;
        getline(cin, _);
        while (true) {
            string line;
            getline(cin, line);
            if (line == "0") break;
            cout << compute(n, line) << "\n";
        }
        cout << "\n";
    }
}
