import java.util.Arrays;
import java.util.Scanner;

public class balanceamento {
    static int[] nums = new int[6];
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int biggest = 1;
        for (int i = 0; i < 6; i++) {
            int in = scn.nextInt();
            nums[i] = in;
            if (in > biggest) {
                biggest = in;
            }
        }
        Arrays.sort(nums);
        int[] middle = sumMatches(biggest);
        if (middle == null) System.out.println("N");
        else {
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                if (i == middle[0] || i == middle[1]) continue;
                sum += nums[i];
            }
            if (sum == biggest) System.out.println("S");
            else System.out.println("N");
        }
    }

    private static int[] sumMatches(int sum) {
        for (int i = 0; i < 5; i++) {
            for (int j = i+1; j < 5; j++) {
                if (nums[i] + nums[j] == sum) return new int[]{i, j};
            }
        }
        return null;
    }
}