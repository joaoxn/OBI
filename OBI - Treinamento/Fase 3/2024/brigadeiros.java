/*
 * Exercício: https://neps.academy/br/exercise/2927
 * Iniciado: 26/09/25 11:31
 * Resolvido em: NÃO RESOLVIDO (16/100)
 */

import java.util.*;

public class brigadeiros {
    static Scanner scan = new Scanner(System.in);
    static int n, k;
    static int[] p;
    static int[][][] dp;

    public static void main(String[] args) {
        n = scan.nextInt(); // 1 <= n <= 300
        k = scan.nextInt(); // tamanho do grupo. 1 <= k <= n
        int t = scan.nextInt(); // 1 <= t <= 10^9

        dp = new int[k+1][n+1][t+1];

        for (int[][] matrix : dp) {
            for (int[] arr : matrix) {
                Arrays.fill(arr, -1);
            }
        }

        p = new int[n];

        for (int i = 0; i < n; i++) {
            p[i] = scan.nextInt();
        }

        int[] memb = new int[k];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (scan.nextInt() == 1) {
                memb[j] = i;
                j++;
            }
        }

        System.out.println(sol(k, n, t));
    }

    // a = membros  b = pratos  t = tempo
    static int sol(int a, int b, int t) {
        if (dp[a][b][t] != -1) return dp[a][b][t];
        if (t <= 0) return 0;


        return -1;
    }
}

/*
 * 3s
 * 9 9 9 0 1
 * 0 1 0 0 1
 */
