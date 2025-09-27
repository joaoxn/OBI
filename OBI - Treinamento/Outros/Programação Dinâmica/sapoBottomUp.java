/*
 * Exercício: https://atcoder.jp/contests/dp/tasks/dp_b
 * Iniciado: 26/09/25 11:11
 * Resolvido em: 26/09/25 11:18 (7m)
 */

import java.util.*;

public class sapoBottomUp {
    static Scanner scan = new Scanner(System.in);
    static int n, k;
    static int[] h;

    public static void main(String[] args) {
        n = scan.nextInt();
        k = scan.nextInt();
        h = new int[n];

        for (int i = 0; i < n; i++) {
            h[i] = scan.nextInt();
        }

        int[] dp = new int[n];
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = Math.max(0, i-k); j < i; j++) {
                int v = Math.abs(h[j]-h[i]) + dp[j];
                if (v < min) min = v;
            }
            dp[i] = min;
        }

        System.out.println(dp[n-1]);
    }
}
