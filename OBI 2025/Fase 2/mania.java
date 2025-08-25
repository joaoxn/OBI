/*
 * 100/100 Pontos - Todas as Subtarefas resolvidas
 */

import java.util.Scanner;

public class mania {
    static Scanner scan = new Scanner(System.in);
    static int n;
    static int m;
    static int[][] g;

    public static void main(String[] args) {
        n = scan.nextInt();
        m = scan.nextInt();
        g = new int[n][m];

        int parMoves = 0;
        int imparMoves = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = scan.nextInt();
                int modulo = g[i][j] % 2;
                int grid = (i+j) % 2;
                if (modulo == grid) 
                    imparMoves++;
                else
                    parMoves++;
            }
        }

        if (parMoves < imparMoves) {
            System.out.println(parMoves);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int modulo = g[i][j] % 2;
                    int grid = (i+j) % 2;
                    if (modulo != grid) g[i][j]++;
                    System.out.print(g[i][j] + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println(imparMoves);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int modulo = g[i][j] % 2;
                    int grid = (i+j) % 2;
                    if (modulo == grid) g[i][j]++;
                    System.out.print(g[i][j] + " ");
                }
                System.out.println();
            }
        }
    }
}
