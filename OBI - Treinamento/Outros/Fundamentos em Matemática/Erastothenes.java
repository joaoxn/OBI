/*
 * Exercício: https://neps.academy/br/exercise/295
 * Iniciado: 16/08/25 16:03
 * Resolvido em: 16/08/25 16:21 (18m)
 */

import java.util.Arrays;
import java.util.Scanner;

public class Erastothenes {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scan.nextInt();

        boolean[] primos = sieveOfErastothenes(n);
        for (int i = 2; i < primos.length; i++) {
            if (!primos[i]) continue;
            System.out.print(i +" ");
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
