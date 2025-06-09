import java.util.Scanner;

public class leilao {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        String[] nomes = new String[n];
        int[] vals = new int[n];

        for (int i = 0; i < n; i++) {
            nomes[i] = scan.next();
            vals[i] = scan.nextInt();
        }

        String holder = "";
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (vals[i] > max) {
                max = vals[i];
                holder = nomes[i];
            }
        }

        System.out.println(holder);
        System.out.println(max);
    }
}
