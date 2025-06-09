import java.util.Scanner;

public class figurinhas {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int c = scan.nextInt();
        int m = scan.nextInt();

        int[] carimbadas = new int[c];

        for (int i = 0; i < c; i++) {
            carimbadas[i] = scan.nextInt();
        }

        int[] compradas = new int[m];
        for (int i = 0; i < m; i++) {
            compradas[i] = scan.nextInt();
        }

        int faltante = 0;

        CARIMBADAS:
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < m; j++) {
                if (carimbadas[i] == compradas[j])
                    continue CARIMBADAS;
            }
            faltante++;
        }

        System.out.println(faltante);
    }
}
