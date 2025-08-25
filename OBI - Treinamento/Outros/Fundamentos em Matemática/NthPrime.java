/*
 * Exercício: https://neps.academy/br/exercise/288
 */

import java.util.ArrayList;
import java.util.Scanner;

public class NthPrime {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scan.nextInt();

        ArrayList<Integer> primes = new ArrayList<>();
        for (int i = 2; primes.size() < n; i++)
            if (isPrime(i, primes))
                primes.add(i);

        System.out.println(primes.get(n-1));
    }

    public static boolean isPrime(int x, ArrayList<Integer> primes) {
        for (Integer p : primes) {
            if (p*p > x) return true;
            if (x % p == 0) return false;
        }
        return true;
    }
}
