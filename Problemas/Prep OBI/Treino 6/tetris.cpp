#include <bits/stdc++.h>
using namespace std;

int n;

struct Jogador {
    int score;
    string nome;

    bool operator <(const Jogador &other) const {
        if (score == other.score) return nome > other.nome;
        return score < other.score;
    }
};

priority_queue<Jogador> pq;

int main() {
    for (int t = 1; cin >> n && (n!=0); ++t) {
        for (int i = 0; i < n; ++i) {
            string nome;
            cin >> nome;
            int score = 0;
            int maior = -1;
            int menor = INT_MAX;
            for (int j = 1; j <= 12; ++j) {
                int x;
                cin >> x;
                score += x;
                if (x < menor) menor = x;
                if (x > maior) maior = x;
            }
            score -= (menor + maior);
            pq.push({score,nome});
        }

        printf("Teste %d\n", t);
        int last = -1;
        int pos = 1;
        for (int i = 1; !pq.empty(); ++i) {
            Jogador curr = pq.top();
            pq.pop();
            if (curr.score != last) pos = i;
            last = curr.score;
            printf("%d %d %s\n", pos, curr.score, curr.nome.c_str());
        }
        printf("\n");
    }

    return 0;
}