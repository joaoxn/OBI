//
// Created by xnaxg on 01/06/2025.
// Exercício: https://neps.academy/br/exercise/2071
// Resolvido em: 11m:50s
//


import java.util.Arrays;
import java.util.Scanner;

public class maior {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int s = scan.nextInt();

        int num = -1;
        for (int i = m; i >= n; i--) {
            String[] numStr = Integer.toString(i).split("");
            int sum = Arrays.stream(numStr).mapToInt(Integer::parseInt).sum();
            if (sum == s) {
                num = i;
                break;
            }
        }
        System.out.println(num);
    }
}
