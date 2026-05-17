#include <bits/stdc++.h>
using namespace std;

int n, f;
vector<int> c;

long long fortuna(int dia) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += dia/c[i];
    }
    return total;
}

int main() {
    scanf("%d %d", &n, &f);
    c.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int l = 1;
    int r = 1000000000;
    int mid = (l+r)/2;
    while (l <= r) {
        long long moedas = fortuna(mid);
        if (moedas >= f) r = mid-1;
        if (moedas < f) l = mid+1;
        mid = (l+r)/2;
    }
    printf("%d\n", mid+1);

    return 0;
}

/*
a//x + a//y + a//z >= f
(a-a%x)/x + (a-a%y)/y + (a-a%z)/z >= f

((a-a%x)y + (a-a%y)x)/xy + (a-a%z)/z

((a-a%z)xy+(a-a%y)xz+(a-a%x)yz)/xyz >= f
(a-a%z)xy+(a-a%y)xz+(a-a%x)yz >= f*xyz

axy-(a%z)xy+axz-(a%y)xz+ayz-(a%x)yz >= fxyz
a(xy+xz+yz)-(a%z)xy-(a%y)xz-(a%x)yz

a(xy+xz+yz) >= fxyz + (a%z)xy+(a%y)xz+(a%x)yz
a >= (fxyz+(a%z)xy+(a%y)xz+(a%x)yz)/(xy+xz+yz)
Não dá pra resolver com matemática!

*/