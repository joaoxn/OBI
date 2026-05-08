#include <bits/stdc++.h>
using namespace std;

int n;

map<char,char> complement = {
    {')','('},
    {']','['},
    {'}','{'}
};

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        stack<char> s;

        string cadeia;
        cin >> cadeia;

        bool success = true;
        for (char c : cadeia) {
            switch (c) {
                case '(': case '[': case '{':
                    s.push(c);
                    break;
                case ')': case ']': case '}':
                    if (s.empty() || s.top() != complement[c]) {
                        success = false;
                        goto END;
                    };
                    s.pop();
                    break;
            }
        }
        END:
        printf("%c\n", success && s.empty() ? 'S' : 'N');
    }

    return 0;
}

/*
[(])
*/