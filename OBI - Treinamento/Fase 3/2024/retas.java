/*
 * Exercício: https://neps.academy/br/exercise/2930
 * Iniciado: 21/09/25 20:29
 * Resolvido em: NÃO RESOLVIDO
 */

import java.util.*;

public class retas {
    static Scanner scan = new Scanner(System.in);
    static long[] a;
    static long[] b;
    static long x1;
    static long x2;

    static class Func {
        long i;
        long a;
        long b;
        long y1;
        long y2;
        List<Func> intersected = new ArrayList<>();
        
        Func(long a, long b, long i) {
            this.a = a;
            this.b = b;
            this.i = i;
            this.y1 = call(x1);
            this.y2 = call(x2);
        }

        long call(long x) {
            return (long) a * x + b;
        }
    }

    public static void main(String[] args) {
        int n = scan.nextInt();
        x1 = scan.nextInt();
        x2 = scan.nextInt();
        
        Comparator<Func> comp_y1 = (f1, f2) -> Long.compare(f1.y1, f2.y1)!=0
            ? Long.compare(f1.y1, f2.y1)
            : Long.compare(f1.y2, f2.y2)!=0
            ? Long.compare(f1.y2, f2.y2) : Long.compare(f1.i, f2.i);

        Comparator<Func> comp_y2 = (f1, f2) -> Long.compare(f1.y2, f2.y2)!=0
            ? Long.compare(f1.y2, f2.y2)
            : Long.compare(f1.y1, f2.y1)!=0
            ? Long.compare(f1.y1, f2.y1) : Long.compare(f1.i, f2.i);

        Func[] f_y1 = new Func[n];
        for (int i = 0; i < n; i++) {
            f_y1[i] = new Func(scan.nextInt(), scan.nextInt(), i);
        }

        Arrays.sort(f_y1, comp_y1);
        
        // for (Func func : f_y1) {
        //     System.out.println(func.y1+", "+func.y2);
        // }
        // System.out.println();

        Func[] f_y2 = Arrays.copyOf(f_y1, n);
        Arrays.sort(f_y2, comp_y2);

        // for (Func func : f_y2) {
        //     System.out.println(func.y1+", "+func.y2);
        // }
        
        long total = 0;
        for (int i = 0; i < n-1; i++) {
            Func f = f_y1[i];
            long k = Arrays.binarySearch(f_y2, f, comp_y2);
            
            if (k > i) total += k-i;

            // Func f = f_y1[i];
            // Func g = f_y1[i+1];
            // if (f.y1 == g.y1 || 
            // f.y2 > g.y2) total++;
        }

        long local = 1;
        for (int i = 0; i < n-1; i++) {
            Func f = f_y1[i];
            Func g = f_y1[i+1];
            if (f.y1 == g.y1) {
                local++;
                f.intersected.add(g);
                g.intersected.add(f);
            } else if (local > 0) {
                total += local * (local-1) / 2;
                local = 1;
            }
        }
        total += local * (local-1) / 2;

        local = 1;
        for (int i = 0; i < n-1; i++) {
            Func f = f_y2[i];
            Func g = f_y2[i+1];
            if (f.y2 == g.y2 && !f.intersected.contains(g) 
                            && !g.intersected.contains(f)) 
                local++;
            else if (local > 0) {
                total += local * (local-1) / 2;
                local = 1;
            }
        }
        total += local * (local-1) / 2;

        System.out.println(total);
    }
}
/*
 * 0, 4
 * 3, 5
 * 6, 7
 * 8, 9
 */

/*
 * 0, 4
 * 3, 5
 * 6, 7
 * 8, 9
 */


/*
 * 0, 4
 * 2, 1
 * 3,-5
 * 5, 9
 * 5, 5
 */

/*
 * 3,-5
 * 2, 1
 * 0, 4
 * 5, 5
 * 5, 9
 */

/*
 * 10, x
 * 10, x
 * 10, x
 * 10, x
 */