import java.util.Scanner;

public class acelerador {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        n -= 3;
        n %= 8;
        System.out.println(n-2);
        scan.close();
    }
}
