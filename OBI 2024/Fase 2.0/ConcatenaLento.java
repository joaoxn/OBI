
import java.util.Arrays;
import java.util.Scanner;

public class ConcatenaLento {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int q = scan.nextInt();
        scan.nextLine();

        int[] digitos = nextIntArray(scan, n);

        int[][] consultas = new int[q][];
        for (int i = 0; i < q; i++)
            consultas[i] = nextIntArray(scan, 2);

        for (int[] intervalo : consultas) {
            int[] lista = Arrays.copyOfRange(digitos, intervalo[0] - 1, intervalo[1]);
            System.out.println(potencial(lista));
        }
    }

    public static int potencial(int[] lista) {
        int total = 0;
        int len = lista.length;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (i != j) {
                    total += concatenar(lista[i], lista[j]);
                }
            }
        }
        return total;
    }

    public static int concatenar(int a, int b) {
        return Integer.parseInt(String.valueOf(a) + b);
    }

    public static int[] nextIntArray(Scanner scn, int length) {
        if (length > 0) {
            int[] array = new int[length];

            for (int i = 0; i < length; i++) {
                array[i] = scn.nextInt();
            }
            return array;
        }
        return Arrays.stream(
                scn.nextLine().split("[,.\\s]")
        ).mapToInt(Integer::parseInt).toArray();
    }
}
