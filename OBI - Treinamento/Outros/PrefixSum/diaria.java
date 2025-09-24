/*
 * Exercício: https://neps.academy/br/exercise/1055
 * Iniciado: 14/09/25 4:33
 * Resolvido em: 21/09/25 4:28
 */

// demorei por causa que a resposta era long 😭

import java.util.*;

public class diaria {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scan.nextInt();
        
        int[] k = new int[n];
        int[] p = new int[n];
        int dias = 0;
        for (int i = 0; i < n; i++) {
            k[i] = scan.nextInt();
            p[i] = scan.nextInt();
            dias += k[i];
        }
        
        long[] prefix = new long[dias+1];
        
        int dia = 0;
        for (int i = 0; i < n; i++) {
            for (int j = dia+1; j <= dia+k[i]; j++) {
                prefix[j] = prefix[j-1] + p[i];
            }
            dia += k[i];
        }
        
        int q = scan.nextInt();
        long[] sols = new long[q];
        for (int i = 0; i < q; i++) {
            int x = scan.nextInt();
            int y = scan.nextInt();
            sols[i] = prefix[y] - prefix[x-1];
        }
        for (long sol : sols) {
            System.out.println(sol);
        }
    }
}
