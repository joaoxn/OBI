//TODO: solução incorreta

#include <bits/stdc++.h>
using namespace std;

#define AS 1
#define VALETE 11
#define DAMA 12
#define REI 13

int p, m, n;

int naipeValue(char naipe) {
    switch (naipe) {
        case 'C': return 1;
        case 'D': return 2;
        case 'H': return 3;
        case 'S': return 4;
        default: return 0;
    }
}

struct Carta {
    int x;
    char s;

    bool jogavel(Carta &mesa) {
        return s == mesa.s || x == mesa.x;
    }

    bool operator <(const Carta &other) const {
        if (x != other.x) return x < other.x;
        return naipeValue(s) < naipeValue(other.s);
    }
};

int next(int pos, int dir) {
    if (pos == -1) return 0;
    pos += dir;
    while (pos < 0) {
        pos += p;
    }
    return pos % p;
}

int main() {
    while (cin >> p >> m >> n && (p!=0 || m!=0 || n!=0)) {
        list<Carta> plr[p];

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < m; j++) {
                Carta c = {};
                cin >> c.x >> c.s;
                plr[i].push_back(c);
            }
        }

        int pos = -1;
        int dir = 1;
        Carta mesa = {};
        cin >> mesa.x >> mesa.s;

        int vencedor = -2;

            // LOOP entre Jogadores
        while (true) {
            //* MODIFICADORES
            if (testarMesa && mesa.x == DAMA) {
                dir *= -1;
                printf("dir: %d (DAMA)\n", dir);
            }
            pos = next(pos,dir);
            list<Carta> *cartas = &plr[pos];
            
            if (testarMesa) {
                testarMesa = false;
                if (mesa.x == VALETE) {
                    printf("%d é pulado (por VALETE)\n", pos+1);
                    continue;
                }
                if (mesa.x == AS || mesa.x == 7) {
                    Carta c1 = Carta{};
                    cin >> c1.x >> c1.s;
                    cartas->push_back(c1);
                    ++i;

                    if (mesa.x == 7) {
                        Carta c2 = Carta{};
                        cin >> c2.x >> c2.s;
                        cartas->push_back(c2);
                        ++i;
                        printf("%d compra: %d %c (por 7) [%d cartas]\n", pos+1, c1.x, c1.s, cartas->size());
                        printf("%d compra: %d %c (por 7) [%d cartas]\n", pos+1, c2.x, c2.s, cartas->size());
                    } else {
                        printf("%d compra: %d %c (por AS) [%d cartas]\n", pos+1, c1.x, c1.s, cartas->size());
                    }
                    continue;
                }
            }
            testarMesa = true;

            //* ESCOLHA E DESCARTE DE CARTAS
            auto best = cartas->end();
            for (auto it = cartas->begin(); it != cartas->end(); ++it) {
                Carta carta = *it;
                if (!carta.jogavel(mesa)) continue;
                if (best == cartas->end() || *best < carta) best = it;
            }
            if (best == cartas->end())
                break;

            printf("%d descarta: %d %c (mesa %d %c) [%d cartas]\n", pos+1, best->x, best->s, mesa.x, mesa.s, cartas->size()-1);
            mesa = *best;
            cartas->erase(best);
            if (cartas->empty()) {
                vencedor = pos;
                goto RESULT;
            }
        }
        
        RESULT:
        printf("%d\n", vencedor+1);


    }
}

/*
2 2 10
1 D
7 D
 1 S
 3 C

13 D

1 S
5 H
12 D
7 S
2 C


3 2 11
1 S
7 D
 11 D
 3 D
7 D
3 S

11 C

8 C
9 H
6 H
9 S


3 3 16
1 H
10 C
13 D
 7 C
 10 H
 2 S
2 C
10 S
8 S

12 H

11 C
1 C
1 C
4 S
5 D
6 S
0 0 0

*1: -1H--10C- 13D  -1C- 4s
*2: -7C--10H-  2S   6S
*3: -2C- 10S   8S -11C- 5D

*12H 1H 10H 10C 11C 2C 7C
!12:*-1 11:skip 1:+1 7:+2

dir: -1 (DAMA)
1 descarta: 1 H (mesa 12 H) [2 cartas]
3 compra: 11 C (por AS) [4 cartas]
2 descarta: 10 H (mesa 1 H) [2 cartas]
1 descarta: 10 C (mesa 10 H) [1 cartas]
3 descarta: 11 C (mesa 10 C) [3 cartas]
2 é pulado (por VALETE)
1 compra: 1 C (por falta) [2 cartas]
3 descarta: 2 C (mesa 11 C) [2 cartas]
2 descarta: 7 C (mesa 2 C) [1 cartas]
1 compra: 1 C (por 7) [4 cartas]
1 compra: 4 S (por 7) [4 cartas]
3 compra: 5 D (por falta) [3 cartas]
2 compra: 6 S (por falta) [2 cartas]
1 descarta: 1 C (mesa 7 C) [3 cartas]
3 compra: 0 0 (por AS) [4 cartas]
-1


*/