import java.util.Scanner;

public class barras {
    static Scanner scan = new Scanner(System.in);
    static int n = scan.nextInt();
    static int[] x = new int[n];
    public static void main(String[] args) {
        int max = 0;
        for (int i = 0; i < n; i++) {
            x[i] = scan.nextInt();
            if (x[i] > max) max = x[i];
        }

        for (int i = max-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                System.out.print(x[j] > i ? 1 : 0);
                System.out.print(' ');
            }
//            if (i != 0)
                System.out.println();
        }
    }
}
