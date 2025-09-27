/*
 * Exercício: 
 * Iniciado: 26/09/25 14:46
 * Resolvido em: NÃO RESOLVIDO
 */

import java.util.*;

public class lcs {
    static Scanner scan = new Scanner(System.in);
    static char[] s, t;
    static int[][] dp; // 3000*3000 estados

    public static void main(String[] args) {
        s = scan.nextLine().toCharArray();
        t = scan.nextLine().toCharArray();
        dp = new int[s.length][t.length];
        for (int i = 0; i < s.length; i++) {
            Arrays.fill(dp[i], -1);
        }

        sol(0,0);
        System.out.println(sol_str.toString());
    }
    
    static StringBuilder sol_str = new StringBuilder();
    static void sol(int i, int j) {
        if (i >= s.length || j >= t.length) return;
        if (s[i]==t[j]) {
            sol_str.append(s[i]);
            sol(i+1, j+1);
            return;
        }
        if (lcs_size(i+1, j) >= lcs_size(i, j+1)) {
            sol(i+1, j);
            return;
        }
        sol(i, j+1);
    }

    static int lcs_size(int i, int j) {
        if (i >= s.length || j >= t.length) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) return lcs_size(i+1, j+1)+1;
        return Math.max(lcs_size(i+1, j), lcs_size(i, j+1));
    }
}
