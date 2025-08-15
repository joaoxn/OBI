/*
 * Exercício: https://neps.academy/br/exercise/205
 * Iniciado: 13/08/25 18:33
 * Resolvido em: 13/08/25 19:52 (42m)
 */

import java.util.Scanner;

class capsulas {
    static Scanner scan = new Scanner(System.in);
    static int n = scan.nextInt();
    static int f = scan.nextInt();
    static int[] c = new int[n];

    public static void main(String[] args) {
        int maxCicle = 0;
        for (int i = 0; i < n; i++) {
            c[i] = scan.nextInt();
            if (c[i] > maxCicle) maxCicle = c[i];
        }

        double perDay = 0;
        for (int i = 0; i < n; i++) {
            perDay += 1d / c[i];
        }

        int mid = (int) (f / perDay);
        int lo = mid - maxCicle;
        int hi = mid + maxCicle + 1;
        // lo = 1;
        // hi = 100000000;

        int closestDiff = Integer.MAX_VALUE;
        int closest = mid;
        while (hi >= lo) {
            mid = (hi+lo)/2;
            int curr = moneyAt(mid);
            if (curr >= f) {
                if (curr - f < closestDiff || curr-f == closestDiff && mid < closest) {
                    closestDiff = curr-f;
                    closest = mid;
                }
                hi = mid-1;
            }
            if (curr < f) {
                lo = mid+1;
            }
        }
        System.out.println(closest);
    }

    public static int moneyAt(int day) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += day/c[i];
        }
        return result;
    }
}