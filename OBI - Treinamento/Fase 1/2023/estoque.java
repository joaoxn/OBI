import java.util.Scanner;

public class estoque {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int m = scan.nextInt(); // Qtd de Tipos
        int n = scan.nextInt(); // Qtd de Tamanhos

        int[][] estoque = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                estoque[i][j] = scan.nextInt();
            }
        }

        int vendas = 0;

        int p = scan.nextInt();
        for (int i = 0; i < p; i++) {
            int tipo = scan.nextInt()-1;
            int tamanho = scan.nextInt()-1;
            if (estoque[tipo][tamanho] == 0) continue;
            estoque[tipo][tamanho]--;
            vendas++;
        }
        System.out.println(vendas);
    }
}
