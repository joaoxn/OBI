/*
 * Exercício: https://atcoder.jp/contests/dp/tasks/dp_b
 * Iniciado: 26/09/25 10:32
 * Resolvido em: 26/09/25 11:05 (30m)
 */

import java.util.*;

public class sapoTopDown {
    static Scanner scan = new Scanner(System.in);
    static int n, k;
    static int[] h;

    static int[] dp;

    public static void main(String[] args) {
        n = scan.nextInt();
        k = scan.nextInt();

        dp = new int[n];
        Arrays.fill(dp, -1);

        h = new int[n];
        for (int i = 0; i < n; i++)
            h[i] = scan.nextInt();

        System.out.println(sol(n-1));
    }

    static int max(int... x) {
        int max = Integer.MIN_VALUE;
        for (int i : x) {
            if (i > max) max = i;
        }
        return max;
    }

    static int min(int... x) {
        int min = Integer.MAX_VALUE;
        for (int i : x) {
            if (i < min) min = i;
        }
        return min;
    }

    static int sol(int i) {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];

        int min = Integer.MAX_VALUE;
        for (int j = max(0, i-k); j < i; j++) {
            int v = sol(j) + Math.abs(h[j]-h[i]);
            if (v < min) min = v;
        }

        dp[i] = min;
        return min;
    }
}
