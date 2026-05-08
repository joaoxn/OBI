#include <bits/stdc++.h>
using namespace std;

int n;
int mat[10][10];

int main() {
    int magicSum = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 0) sum = INT_MIN;
            else sum += mat[i][j];
        }
        if (magicSum == -1 && sum >= 0) magicSum = sum;
    }

    if (magicSum == -1) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][j] == 0) sum = INT_MIN;
                else sum += mat[i][j];
            }
            if (sum >= 0) {
                magicSum = sum;
                break;
            };
        }
    }
    if (magicSum == -1) {
        if (mat[0][0] != 0 && mat[1][1] != 0 && mat[2][2] != 0) {
            magicSum = mat[0][0] + mat[1][1] + mat[2][2];
        } else if (mat[0][2] != 0 && mat[1][1] != 0 && mat[2][0] != 0) {
            magicSum = mat[0][2] + mat[1][1] + mat[2][0];
        }
    }

    if (magicSum == -1) {
        //*a = (s2+s3-s1)/2
        //*b = a+s1-s2
        //*c = s1-b

        int s1 = mat[0][0]+mat[0][1]+mat[0][2];
        int s2 = mat[1][0]+mat[1][1]+mat[1][2];
        int s3 = mat[2][0]+mat[2][1]+mat[2][2];

        int a = (s2+s3-s1)/2;
        int b = a+s1-s2;
        int c = s1-b;

        for (int i = 0; i < n; i++) {
            if (mat[0][i] == 0) {
                mat[0][i] = a;
            }
            if (mat[1][i] == 0) {
                mat[1][i] = b;
            }
            if (mat[2][i] == 0) {
                mat[2][i] = c;
            }
        }
    }
    int zeroi = 0;
    int zeroj = 0;

    for (int i = 0; i < n; i++) {
        int zeros = 0;
        int zero_j = -1;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += mat[i][j];
            if (mat[i][j] == 0) {
                ++zeros;
                zero_j = j;
            }
        }
        if (zeros == 1) {
            mat[i][zero_j] = magicSum - sum;
            zeroi = i;
            zeroj = zero_j;
        }
    }
    
    for (int j = 0; j < n; j++) {
        int zeros = 0;
        int zero_i = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[i][j];
            if (mat[i][j] == 0) {
                ++zeros;
                zero_i = i;
            }
        }
        if (zeros == 1) {
            mat[zero_i][j] = magicSum - sum;
            zeroi = zero_i;
            zeroj = j;
        }
    }

    printf("%d\n%d\n%d\n", mat[zeroi][zeroj], zeroi+1, zeroj+1);

    return 0;
}

/*
4 9 2
3 0 7
8 1 6

0 9 2
3 0 7
8 1 0

495 468 0
0 522 414
441 0 549

1 1 0
1 0 1
0 1 1

0 1 1
1 0 1
1 1 0

a 1 1
1 b 1
1 1 c

a+b+c = s1+a = s2+b = s3+c

b+c = s1
a+c = s2
a+b = s3

c = s1-b
a+s1-b = s2
2a+s1 = s2+s3
a = (s2+s3-s1)/2

//*a = (s2+s3-s1)/2
//*b = a+s1-s2
//*c = s1-b

*/