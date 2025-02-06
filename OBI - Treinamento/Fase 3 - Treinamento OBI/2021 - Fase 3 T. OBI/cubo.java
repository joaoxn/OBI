import java.util.Scanner;

public class cubo {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        
        int n1 = scn.nextInt();
        int n2 = scn.nextInt();

        int count = 0;
        for (int i = n1; i <= n2; i++) {
            if (Math.sqrt(i) == (int) Math.sqrt(i) && Math.cbrt(i) == (int) Math.cbrt(i)) count++;
        }

        System.out.println(count);
    }
}
