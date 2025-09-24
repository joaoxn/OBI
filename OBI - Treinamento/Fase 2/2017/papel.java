/*
 * Exercício: https://neps.academy/br/exercise/27
 * Iniciado: 24/08/25 20:13
 * Resolvido em: NÃO RESOLVIDO
 */

import java.util.Scanner;

public class papel {
    static Scanner scan = new Scanner(System.in); 
    static int n;
    static int[] a;
    public static void main(String[] args) {
        n = scan.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scan.nextInt();
        }
        @SuppressWarnings("unused")
        int count = 1;
        
    }
}

/*
 * [0, -15, 5, -5, 10, 0, 0, -10, 1, 16]
 */

/*
 * [20, 5, 10, 5, 15, 15, 15,  5, 6, 22] -> 5
 */