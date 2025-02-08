import java.util.Arrays;
import java.util.Scanner;

public class contas {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int v = scan.nextInt();
        int[] contas = new int[3];

        for (int i = 0; i < contas.length; i++) {
            contas[i] = scan.nextInt();
        }

        Arrays.sort(contas);

        int max = 0;
        for (int conta : contas) {
            if (v - conta < 0) {
                break;
            }
            v -= conta;
            max++;
        }
        System.out.println(max);
    }
}
