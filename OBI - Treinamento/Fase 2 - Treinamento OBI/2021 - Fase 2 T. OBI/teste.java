import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class teste {

    private static int[][] matriz;
    private static int[][] maxPower;
    private static int n, m;
    private static final int[] dx = {-1, 1, 0, 0}; // Movimentos em x (cima, baixo)
    private static final int[] dy = {0, 0, -1, 1}; // Movimentos em y (esquerda, direita)

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        m = scanner.nextInt();

        matriz = new int[n][m];
        maxPower = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matriz[i][j] = scanner.nextInt();
                maxPower[i][j] = matriz[i][j]; // Inicializa maxPower com os valores iniciais de poder
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bfs(i, j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(maxPower[i][j] + " ");
            }
            System.out.println();
        }

        scanner.close();
    }

    private static void bfs(int x, int y) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x, y, maxPower[x][y]});

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int cx = current[0];
            int cy = current[1];
            int cp = current[2];

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && cp >= matriz[nx][ny]) {
                    int newPower = cp + matriz[nx][ny];
                    if (newPower > maxPower[nx][ny]) {
                        maxPower[nx][ny] = newPower;
                        queue.add(new int[]{nx, ny, newPower});
                    }
                }
            }
        }
    }
}
