import java.util.Scanner;

public class calculo {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int s = scn.nextInt();
        int a = scn.nextInt();
        int b = scn.nextInt();

        int qtd = 0;

        for (int i = a; i <= b; i++) {
            int sum = 0;
            for (int j = 0; j <= Math.log10(i); j++) {
                sum += (int) (i/(Math.pow(10, j)) % 10);
            }
            if (sum == s)
                qtd++;
        }
        System.out.println(qtd);
        scn.close();
    }
}
