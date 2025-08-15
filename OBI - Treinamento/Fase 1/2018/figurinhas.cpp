#include <iostream>
#include <vector>

using namespace std;

int indexOf(vector<int> vector, int value) {
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == value) return i;
    }
    return -1;
}

auto calc() {
    int n, c, m;
    cin >> n >> c >> m;

    vector<int> carimbadas(c);
    for (int i = 0; i < c; i++) {
        cin >> carimbadas[i];
    }

    int compradas[m];
    for (int i = 0; i < m; i++) {
        cin >> compradas[i];
        const int index = indexOf(carimbadas, compradas[i]);
        if (index == -1) continue;
        carimbadas[index] = 0;
    }

    int counter = 0;
    for (int i = 0; i < c; i++) {
        if (carimbadas[i] > 0) counter++;
    }
    return counter;
}

int main() {
    auto res = calc();
    cout << res << endl;
}
