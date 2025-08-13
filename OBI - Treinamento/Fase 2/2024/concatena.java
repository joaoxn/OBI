import java.util.Scanner;

public class concatena {
    static Scanner scan = new Scanner(System.in);
    static int n = scan.nextInt();
    static int q = scan.nextInt();
    static int[] d = new int[n+1];
    static int[][] pMemo = new int[n+1][n+1];

    public static void main(String[] args) {

        for (int i = 1; i <= n; i++) {
            d[i] = scan.nextInt();
        }

        int[] r = new int[q];
        for (int i = 0; i < q; i++) {
            r[i] = potencial(scan.nextInt(), scan.nextInt());
        }
        for (int i = 0; i < r.length; i++) {
            System.out.println(r[i]);
        }
    }

    public static int potencial(int a, int b) {
        if (a == b) return 0;
        if (pMemo[a][b] != 0) return pMemo[a][b];

        int sum = 0;
        for (int i = b-1; i >= a; i--) {
            int localSum = 0;
            
            if (pMemo[i][b] != 0) return pMemo[i][b];
            for (int j = i+1; j <= b; j++) {
                localSum += concat(d[i], d[j]) + concat(d[j], d[i]);
            }
            pMemo[i][b] = localSum;
            sum += localSum;
        }

        return sum;
    }

    public static int potencialRecursivo(int i, int j) {
        if (i == j) return 0;
        if (pMemo[i][j] != 0) return pMemo[i][j];
        if (j-i == 1) return concat(d[i], d[j]) + concat(d[j], d[i]);

        int sum = potencial(i+1, j);
        for (int k = i+1; k <= j; k++) {
            sum += concat(d[i], d[k]) + concat(d[k], d[i]);
        }
        pMemo[i][j] = sum;
        return sum;
    }

    public static int concat(int a, int b) {
        int val = Integer.valueOf(String.valueOf(a)+String.valueOf(b));
        return val;
    }
}

/*
 * 1 2 3
 * 12
 * 31
 * 32
 * 
 */
