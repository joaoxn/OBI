/*
 * Exercício: 
 * Iniciado: 17/08/25 16:40
 * Resolvido em: /08/25 
 */

import java.util.*;

public class ParqueDeDiversoes {
    static Scanner scan = new Scanner(System.in);
    static int n;
    static int m;
    static Map<Integer, List<Integer>> map = new HashMap<>(); 

    public static void main(String[] args) {
        n = scan.nextInt();
        m = scan.nextInt();

        boolean[] isPrime = erastothenes(n);
        

        for (int i = 0; i < m; i++) {
            int u = scan.nextInt();
            int v = scan.nextInt();
            if (!isPrime[u] || !isPrime[v]) continue;

            map.putIfAbsent(u, new ArrayList<>());
            map.putIfAbsent(v, new ArrayList<>());
            map.get(u).add(v);
            map.get(v).add(u);
        }


    }

    // 2 3
    // 3 7
    // -> 5

    public static boolean[] erastothenes(int n) {
        boolean[] isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int p = 2; p*p <= n; p++) {
            if (!isPrime[p]) continue;
            for (int i = p*p; i <= n; i += p)
                isPrime[i] = false;
        }

        return isPrime;
    }
}
