//
// Created by xnaxg on 08/04/2026.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

};

struct Stack {
    Node* T;

    void push(int val) {
        Node* node = new Node{val, T};
        T = node;
    }
    int pop() {
        int val = T->val;
        Node* past = T;
        T = T->next;
        delete past;
        return val;
    }
    [[nodiscard]] int top() const {
        return T->val;
    }
};

int main() {
    Stack s{};
    s.push(134);
    cout << s.top() << endl;
    s.push(2);
    s.push(34);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
}