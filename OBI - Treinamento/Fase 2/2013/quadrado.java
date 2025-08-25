/*
 * Exercício: https://neps.academy/br/exercise/508
 * Iniciado: 24/08/25 10:45
 * Resolvido em: 24/08/25 19:58 (50m)
 */

/*
 * Dado um array de tamanho n tal que 1 <= n <= 10^6, 
 * calcule quantos subarrays existem tal que a soma do subarray é divisível por 8
 */

import java.util.Scanner;

class quadrado {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scan.nextInt(); // n < 10^6
        // O(nlog(n)) = 2*10^7

        int[] ns = new int[n]; // [3, 4, 6, 0, 2, 9]
        for (int i = 0; i < n; i++) {
            ns[i] = scan.nextInt();
        }

        int[] prefixSum = new int[n+1]; // [0, 3, 7, 13, 13, 15, 24]
        for (int i = 1; i < n+1; i++) {
            prefixSum[i] = prefixSum[i-1] + ns[i-1];
        }

        long count = 0;
        for (int r = 0; r < 8; r++) {
            long amt = 0;
            for (int i = 0; i < prefixSum.length; i++) {
                if (prefixSum[i] % 8 == r) amt++;
            }
            long comb = amt*(amt-1)/2;
            count += comb;
        }
        System.out.println(count);
    }
}
