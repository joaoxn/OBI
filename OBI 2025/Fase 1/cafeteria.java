import java.util.Scanner;

public class cafeteria {
    static Scanner scan = new Scanner(System.in);
    static int a = scan.nextInt();
    static int b = scan.nextInt();
    static int c = scan.nextInt();
    static int d = scan.nextInt();

    public static void main(String[] args) {
        char success = 'N';
        int espaco = c;
        while (espaco <= c && espaco >= a) {
            if (espaco <= b) {
                success = 'S';
                break;
            }
            espaco -= d;
        }
        System.out.println(success);
    }
}
