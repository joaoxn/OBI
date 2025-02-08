import java.util.*;

public class compensacao {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int m = scan.nextInt();
        int n = scan.nextInt();

        int[] balance = new int[n];
        int[] original = new int[n];

        for (int i = 0; i < m; i++) {
            int x = scan.nextInt()-1;
            int v = scan.nextInt();
            int y = scan.nextInt()-1;

            balance[x] -= v;
            balance[y] += v;
            original[y] += v;
        }

        int sum = 0;
        int originalSum = 0;
        for (int i = 0; i < n; i++) {
            sum += Math.max(balance[i], 0);
            originalSum += original[i];
        }
        System.out.println(sum == originalSum ? 'N' : 'S');
        System.out.println(sum);
    }
}
