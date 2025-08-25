/*
 * 100/100 Pontos - Todas as Subtarefas resolvidas
 */

import java.util.Scanner;

class distinto {
    static Scanner scan = new Scanner(System.in);
    static int p;

    public static void main(String[] args) {
        p = scan.nextInt();         // 1 <= P <= 5*10^4 (50 000)

        long[] solutions = new long[p];
        for (int i = 0; i < p; i++) {
            long l = scan.nextLong();   // 1 <= L <= 10^12
            long a = scan.nextLong();   // 1 <= A <= B <= 2*10^9
            long b = scan.nextLong();   // 1 <= A <= B <= 2*10^9
            solutions[i] = solve(l, a, b);
        }
        for (int i = 0; i < p; i++) {
            System.out.println(solutions[i]);
        }
    }

    public static long sumPA(long start, long end) {
        return ((start + end) * (end-start+1))/2;
    }

    // x -> sum(A, x-1) < L & x-1 < B & (sum(A,x) >= L || x == B)
    public static long solve(long l, long a, long b) {
        long lo = a;
        long hi = b;
        while(lo <= hi) {
            long x = (lo+hi)/2;
            long sum = sumPA(a, x);
            long sumPrev = sum - x;
            boolean isPrevWithin = sumPrev < l && x-1 < b;
            boolean isCurrOutBounds = sum >= l || x >= b;
            if (isPrevWithin && isCurrOutBounds) {
                //found
                return x-a+1;
            }
            if (isCurrOutBounds) {
                hi = x-1;
            } else {
                lo = x+1;
            }
        }

        return -1;
    }
}