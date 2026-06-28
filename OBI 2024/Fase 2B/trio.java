import java.util.Arrays;
import java.util.Scanner;

public class trio {
    static Scanner scn = new Scanner(System.in);
    static int n = scn.nextInt();
    static int[] ints = new int[n];

    public static void main(String[] args) {
        for (int i = 0; i < n; i++) {
            ints[i] = scn.nextInt();
        }
        System.out.println(countTrios());
    }

    public static int countTrios() {
        Arrays.sort(ints);
        int sol = 0;

        for (int i = 0; i < n; i++) {
            LOOP2:
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (ints[i] >= ints[j] + ints[k] ||
                    ints[j] >= ints[i] + ints[k] ||
                    ints[k] >= ints[i] + ints[j]) {
                        sol++;
                        break LOOP2;
                    }
                }
            }
        }

        for (int i = 0; i < n - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < n - 1; j++) {
                while (k < n && ints[i] + ints[j] > ints[k]) {
                    k++;
                }
                sol += k - j - 1;
            }
        }
        return sol;
    }
}