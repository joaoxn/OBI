import java.util.Scanner;

public class alfabeto {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        @SuppressWarnings("unused")
        int k = scan.nextInt();
        @SuppressWarnings("unused")
        int n = scan.nextInt();

        String alf = scan.next();
        String msg = scan.next();

        boolean result = true;

        OUTER:
        for (int i = 0; i < msg.length(); i++) {
            for (int j = 0; j < alf.length(); j++) {
                if (!alf.contains(msg.substring(i, i+1))) {
                    result = false;
                    break OUTER;
                }
            }
        }

        System.out.println(result ? 'S' : 'N');

        scan.close();
    }
}
