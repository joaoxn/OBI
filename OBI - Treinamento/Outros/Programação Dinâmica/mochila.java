/*
 * Exercício: https://neps.academy/br/exercise/2779
 * Iniciado: 26/09/25 08:43
 * Resolvido em: 26/09/25 09:37 (40m)
 */

import java.util.*;

// ? Complexidade: O(N*C); Max: 10^7
public class mochila {
    static Scanner scan = new Scanner(System.in);
    static int n;
    static int[] peso, valor;
    static long[][] dp;

    public static void main(String[] args) {
        n = scan.nextInt();
        int c = scan.nextInt();
        dp = new long[n][c+1];
        
        peso = new int[n];
        valor = new int[n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
            peso[i] = scan.nextInt();
            valor[i] = scan.nextInt();
        }

        System.out.println(sol(0, c));
        System.out.println();
    }
    static long max(long... x) {
        long max = Integer.MIN_VALUE;
        for (long i : x)
            if (i > max) max = i;
        return max;
    }

    static long min(long... x) {
        long max = Integer.MIN_VALUE;
        for (long i : x)
            if (i > max) max = i;
        return max;
    }

    static long sol(int i, int c) {
        if (i >= n) return 0;
        if (dp[i][c] != -1) {
            return dp[i][c];
        }
        
        long sol = -1;
        if (peso[i] > c) sol = sol(i+1, c);
        else sol = max(sol(i+1, c), sol(i+1, c-peso[i])+valor[i]);

        dp[i][c] = sol;
        return sol;
    }
}
