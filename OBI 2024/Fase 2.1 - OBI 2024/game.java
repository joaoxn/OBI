import java.util.Scanner;

public class game {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        String chars = in.next();

        int sala = 1;

        for (int i = 0; i < n; i++) {
            if (chars.charAt(i) == 'E') sala*=2;
            else sala = sala * 2 + 1;
        }
        System.out.println(sala);
    }
}