//
// Created by xnaxg on {}/{}/2025.
// Exercício: {LINK}
// Resolvido em: {}m:{}s
//


import java.util.Scanner;


public class chuva {

    static byte[] v;
//    static int[][] memo;
    static int n;
    static int s;

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        n = scn.nextInt();
        s = scn.nextInt();

//        memo = new int[n][];
//        for (int i = 0; i < n; i++) {
//            memo[i] = new int[n-i];
//        }

        v = new byte[n];

        for (int i = 0; i < n; i++) {
            v[i] = scn.nextByte();
        }


        int count = 0;
        int left = 0;
        int right = n-1;
        boolean shifted = false;
        boolean shiftToRight = true;
        while (left <= right) {
            int sum = 0;
            for (int i = left; i <= right; i++) {
                sum += v[i];
            }
            if (sum == s) {
                count++;
                if (shifted) break;
                if (shiftToRight) {
                    shifted = true;

                }
            } else if (sum > s) {

            }
        }

        System.out.println(count);
        scn.close();
    }
}
