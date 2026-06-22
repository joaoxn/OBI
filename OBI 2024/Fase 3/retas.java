
import java.util.*;

public class retas {
    static int[][] retas;

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt(), min = scn.nextInt(), max = scn.nextInt();
        retas = new int[n][2];
        int amt = 0;

        for (int i = 0; i < n; i++) {
            retas[i][0] = scn.nextInt();
            retas[i][1] = scn.nextInt();
            if (i != 0) {
                for (int j = i - 1; j >= 0; j--) {
                    float pos = check(i, j);
                    if (pos >= min && pos <= max) {
                        amt++;
                    }
                }
            }
        }

        System.out.println(amt);
    }

    public static float check(int i, int j) {
        int[] r1 = retas[i];
        int[] r2 = retas[j];

        return (float) (r1[1] - r2[1]) / (float) (r2[0] - r1[0]);
    }
}
