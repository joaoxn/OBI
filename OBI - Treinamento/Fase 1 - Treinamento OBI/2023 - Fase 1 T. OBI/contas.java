import java.util.Scanner;

public class contas {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int v = scan.nextInt();
        int[] contas = new int[3];

        for (int i = 0; i < contas.length; i++) {
            contas[i] = scan.nextInt();
        }

        for (int i = 0; i < contas.length-1; i++) {
            int curr = contas[i];
            if (curr > contas[i+1]) {
                contas[i] = contas[i+1];
                contas[i+1] = curr;
            }
        }
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
