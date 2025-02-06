import java.util.Scanner;

public class cubo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int lados0 = (int) Math.max(Math.pow(n-2, 3), 0);
        int lados2 = (n-2)*12;
        int lados3 = 8;

        System.out.println(lados0);
        System.out.println((int) Math.pow(n, 3) - lados2 - lados3 - lados0);
        System.out.println(lados2);
        System.out.println(lados3);
    }
}
