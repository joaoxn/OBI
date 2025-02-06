import java.util.Arrays;
import java.util.Scanner;

public class idade {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int[] idades = new int[] {scan.nextInt(), scan.nextInt(), scan.nextInt()};

        Arrays.sort(idades);

        System.out.println(idades[1]);
    }
}
