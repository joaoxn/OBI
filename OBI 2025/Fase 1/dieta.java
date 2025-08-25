/*
 * 100/100 Pontos - Todas as Subtarefas resolvidas
 */

import java.util.Scanner;

public class dieta {
    static Scanner scan = new Scanner(System.in);
    static int n = scan.nextInt();
    static int m = scan.nextInt();

    public static void main(String[] args) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int p = scan.nextInt() * 4;
            int g = scan.nextInt() * 9;
            int c = scan.nextInt() * 4;
            sum += p + g + c;
        }

        System.out.println(m - sum);
    }
}
