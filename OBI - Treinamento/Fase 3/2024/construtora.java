/*
 * Exercício: 
 * Iniciado: 21/09/25 19:57
 * Resolvido em: 21/09/25 20:13 (15m)
 */

import java.util.*;

public class construtora {
    static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scan.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scan.nextInt();
        }

        int fase;
        for(fase = 0;; fase++) {
            int min = Integer.MAX_VALUE;
            int min_i = -1;
            boolean nivelado = true;
            for (int i = 0; i < a.length; i++) {
                if (a[i] != a[0]) nivelado = false;

                if (a[i] < min) {
                    min = a[i];
                    min_i = i;
                }
            }
            if (nivelado == true) break;

            for (int i = min_i; i < n && a[i] == min; i++)
                a[i]++;

            
        }

        System.out.println(fase);
    }
}
