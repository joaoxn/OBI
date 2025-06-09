import java.util.Scanner;

public class codigo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int qtd = scan.nextInt();
        String in = scan.next();

        for (int i = 0; i < in.length();) {
            int repeats = 1;
            for (int j = 1; j < in.length() - i; j++) {
                if (in.charAt(i+j) == in.charAt(i)) {
                    repeats++;
                } else break;
            }
            System.out.print(repeats + " " + in.charAt(i) + " ");
            i += repeats;
        }
    }
}
