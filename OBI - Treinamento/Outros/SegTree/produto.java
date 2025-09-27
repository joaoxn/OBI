/*
 * Exercício: 
 * Iniciado: 27/09/25 07:57
 * Resolvido em: NÃO RESOLVIDO
 */

import java.util.*;

public class produto {
    static Scanner scan = new Scanner(System.in);
    static long[] seg;
    static int n, k;
    static int[] x;

    public static void main(String[] args) {
        try {
            n = scan.nextInt();
        } catch (NoSuchElementException e) {
            return;
        }
        k = scan.nextInt();
        seg = new long[4*n];

        x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = scan.nextInt();
        }
        build(1, 0, n-1);

        int[] pos = new int[k];
        int[] v = new int[k];
        int[] j = new int[k];
        for (int i = 0; i < k; i++) {
            char comando = scan.next().charAt(0);
            pos[i] = scan.nextInt()-1;
            (comando == 'C' ? v : j)[i] = scan.nextInt();
            if (j[i] != 0) j[i]--;
        }

        for (int i = 0; i < k; i++) {
            int p = pos[i];
            if (j[i] != 0) {
                long res = query(p, j[i], 1, 0, n-1);
                // System.out.print("\n"+res+" ");
                System.out.print(res == 0 ? '0' : res > 0 ? '+' : '-');
                continue;
            }

            update(p, v[i], 1, 0, n-1);
        }
        System.out.println();
        main(args);
    }

    static long build(int p, int l, int r) {
        if (l == r) return seg[p] = x[l];
        int m = (l+r)/2;
        return seg[p] = build(p*2, l, m) * build(p*2+1, m+1, r);
    }


    static long query(int a, int b, int p, int l, int r) {
        if (r < a || l > b) return 1;
        if (a <= l && r <= b) return seg[p];
        
        int m = (l+r)/2;
        return query(a, b, p*2, l, m) * query(a, b, p*2+1, m+1, r);
    }


    static long update(int x, int v, int p, int l, int r) {
        if (l == r) {
            return seg[p] = v;
        }

        int m = (l+r)/2;
        if (x <= m) {
            return seg[p] = update(x, v, p*2, l, m) * seg[p*2+1];
        }
        return seg[p] = update(x, v, p*2+1, m+1, r) * seg[p*2];
    }
}
