/*
 * Exercício: 
 * Iniciado: 14/09/25 10:35
 * Resolvido em: 14/09/25 11:07 (25m)
 */

import java.util.*;

public class arranhaceu {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scan.nextInt();
        int q = scan.nextInt();

        int[] a = new int[n+1];
        for (int i = 1; i <= n; i++) {
            a[i] = scan.nextInt();
        }
        int[] prefixSum = new int[n+1];
        for (int i = 1; i < prefixSum.length; i++) {
            prefixSum[i] = a[i] + prefixSum[i-1];
        }

        ArrayList<Integer> answers = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int type = scan.nextInt();

            if (type == 0) {
                int floor = scan.nextInt();
                int newVal = scan.nextInt();
                int oldVal = a[floor];
                a[floor] = newVal;

                for (int j = floor; j <= n; j++)
                    prefixSum[j] += newVal - oldVal;
            } else {
                answers.add(prefixSum[scan.nextInt()]);
            }
        }

        for (Integer integer : answers) {
            System.out.println(integer);
        }
    }
}
