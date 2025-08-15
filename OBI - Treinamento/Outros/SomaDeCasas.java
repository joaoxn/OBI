/*
 * Exercício: https://neps.academy/br/exercise/255
 * Iniciado: 13/08/25 14:18
 * Resolvido em: 13/08/25 14:31 (12m)
 */

import java.util.Arrays;
import java.util.Scanner;

public class SomaDeCasas {
    static Scanner scan = new Scanner(System.in);
    static int n = scan.nextInt();
    static int[] ns = new int[n];
    static int k;

    public static void main(String[] args) {
        for (int i = 0; i < ns.length; i++) {
            ns[i] = scan.nextInt();
        }
        k = scan.nextInt();

        for (int i = 0; i < ns.length; i++) {
            int goal = k - ns[i];
            int pos = Arrays.binarySearch(ns, goal);
            if (pos > 0) {
                System.out.println(ns[i] +" "+ ns[pos]);
                break;
            }
        }
    }
}
