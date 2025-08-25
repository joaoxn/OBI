/*
 * Iniciado: 08/2025 20:40
 * Resolvido em: 08/2025 20:59 (19m)
 */

import java.util.*;

class placar {
    static Scanner scan = new Scanner(System.in);
    static int p;
    static int[] ps;
    
    static int c;
    static int[] cs;

    public static void main(String[] args) {
        p = scan.nextInt();
        ps = new int[p];
        for (int i = 0; i < p; i++) {
            ps[i] = scan.nextInt();
        }

        c = scan.nextInt();
        cs = new int[c];
        for (int i = 0; i < c; i++) {
            cs[i] = scan.nextInt();
        }

        System.out.println("0 0");
        int i1 = 0;
        int i2 = 0;
        boolean i1Finished = false;
        while (true) {
            if (i1 >= ps.length) {
                i1Finished = true;
                break;
            }
            if (i2 >= cs.length) break;

            if (ps[i1] == cs[i2]) {
                i1++; i2++;
            } else if (ps[i1] < cs[i2]) {
                i1++;
            } else {
                i2++;
            }
            System.out.println(i1 +" "+ i2);
        }

        while (i1Finished && i2 < cs.length || !i1Finished && i1 < ps.length) {
            if (i1Finished) i2++;
            else i1++;

            System.out.println(i1 + " " + i2);
        }
    }
}