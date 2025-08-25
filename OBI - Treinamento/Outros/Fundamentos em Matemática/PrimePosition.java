/*
 * Exercício: https://neps.academy/br/exercise/293
 * Iniciado: 16/08/25 21:59
 * Resolvido em: 16/08/25 22:05 (16m)
 */

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class PrimePosition {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int q = scan.nextInt();
        int[] ns = new int[q];
        int max = -1;
        for (int i = 0; i < q; i++) {
            ns[i] = scan.nextInt();
            if (ns[i] > max) max = ns[i];
        }

        boolean[] sieve = sieveOfErastothenes(max);
        HashMap<Integer, Integer> map = new HashMap<>();
        int primeAmt = 0;
        for (int i = 0; i < sieve.length; i++) {
            if (!sieve[i]) continue;
            primeAmt++;
            map.put(i, primeAmt);
        }

        for (int n : ns) {
            System.out.println(map.get(n));
        }
    }

    public static boolean[] sieveOfErastothenes(int n) {
        boolean[] isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);
        
        isPrime[0] = false;
        isPrime[1] = false;

        for (int p = 2; p*p <= n; p++) {
            if (!isPrime[p]) continue;
            for (int i = p*p; i <= n; i+=p)
                isPrime[i] = false;
        }

        return isPrime;
    }
}
