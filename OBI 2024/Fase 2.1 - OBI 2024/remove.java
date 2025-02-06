import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class remove {
    static int n;
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        n = scn.nextInt();

        int i;
        for (i = 0; n > 0; i++) {
            subtrair();
        }
        System.out.println(i);
    }

    public static void subtrair() {
        int[] algs = algarismos(n);
        int max = 0;
        for (int i = 0; i < algs.length; i++) {
            if (algs[i] > max) max = algs[i];
        }
        n -= max;
    }

    public static int[] algarismos(int n) {
        int[] algs = new int[(int) Math.log10(n)+1];
        for (int i = 0; i < algs.length; i++) {
            algs[i] = (int) (n/(Math.pow(10, i)) % 10);
        }
        return algs;
    }
}