#include <bits/stdc++.h>
using namespace std;

int mat[3][3];

int main() {
    int magicSum = -1;
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 0) sum = INT_MIN;
            else sum += mat[i][j];
        }
        if (magicSum == -1 && sum >= 0) magicSum = sum;
    }

    if (magicSum == -1) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int i = 0; i < 3; i++) {
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

        for (int i = 0; i < 3; i++) {
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

    for (int i = 0; i < 3; i++) {
        int zeros = 0;
        int zero_j = -1;
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += mat[i][j];
            if (mat[i][j] == 0) {
                ++zeros;
                zero_j = j;
            }
        }
        if (zeros == 1) {
            mat[i][zero_j] = magicSum - sum;
        }
    }
    
    for (int j = 0; j < 3; j++) {
        int zeros = 0;
        int zero_i = -1;
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += mat[i][j];
            if (mat[i][j] == 0) {
                ++zeros;
                zero_i = i;
            }
        }
        if (zeros == 1) {
            mat[zero_i][j] = magicSum - sum;
        }
    }

    int zeros = 0;
    int zero_i = -1;
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        int j = i;
        sum += mat[i][j];
        if (mat[i][j] == 0) {
            ++zeros;
            zero_i = i;
        }
    }
    if (zeros == 1) {
        mat[zero_i][zero_i] = magicSum - sum;
    }

    zeros = 0;
    zero_i = -1;
    sum = 0;
    for (int i = 0; i < 3; i++) {
        int j = 2-i;
        sum += mat[i][j];
        if (mat[i][j] == 0) {
            ++zeros;
            zero_i = i;
        }
    }
    if (zeros == 1) {
        mat[zero_i][2-zero_i] = magicSum - sum;
    }

    for (int i = 0; i < 3; i++) {
        printf("%d", mat[i][0]);
        for (int j = 1; j < 3; j++) {
            printf(" %d", mat[i][j]);
        }
        printf("\n");
    }

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