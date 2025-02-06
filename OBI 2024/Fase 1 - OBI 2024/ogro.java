import java.util.Scanner;
import java.util.regex.Pattern;

public class ogro {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int e = scan.nextInt();
        int d = scan.nextInt();

        if (e>d) {
            System.out.println(e+d);
        } else {
            System.out.println(2*(d-e));
        }
    }
}
