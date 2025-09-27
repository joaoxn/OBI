/*
 * Exercício: https://neps.academy/br/exercise/2930
 * Iniciado: 22/09/25 08:30
 * Resolvido em: 22/09/25 09:34 (49m)
 */

import java.util.*;

public class retasBit {
    static class Func implements Comparable<Func> {
    long y1;
    long y2;

    Func(long a, long b) {
        this.y1 = a*x1+b;
        this.y2 = a*x2+b;
    }
    @Override
        public int compareTo(retasBit.Func o) {
            if (this.y1 != o.y1) return Long.compare(this.y1, o.y1);
            return Long.compare(o.y2, this.y2);
        }
}
    
    static Scanner scan = new Scanner(System.in);
    static long x1, x2;
    static int[] bit = new int[(int) 1e5 + 10];
    
    public static void main(String[] args) {
        int n = scan.nextInt();
        x1 = scan.nextInt();
        x2 = scan.nextInt();

        Func[] funcs = new Func[n];
        long[] cc = new long[n]; // Compressão de Coordenadas

        for (int i = 0; i < n; i++) {
            long a = scan.nextInt();
            long b = scan.nextInt();
            funcs[i] = new Func(a, b);
            cc[i] = funcs[i].y2;
        }
        Arrays.sort(funcs);
        Arrays.sort(cc);

        HashMap<Long, Long> map = new HashMap<>();

        // Mapeia cada valor da lista (cc) para um índice menor
        // Quando há um número novo, o valor compVal aumenta em 1

        // Assim, tendo uma lista, exemplo: 10, 20, 20, 30, 40
        // 10 = 1, 20 = 2, 20 igual valor anterior (pula), 30 = 3, 40 = 4
        long compVal = 1;
        map.put(cc[0], compVal);
        for (int i = 1; i < cc.length; i++) {
            if (cc[i] == cc[i-1]) continue;
            map.put(cc[i], ++compVal);
        }
        // Itera sobre cc e atualiza os valores para comprimir, utilizando o map
        for (int i = 0; i < funcs.length; i++) {
            cc[i] = map.get(funcs[i].y2);
        }

        long sum = 0;
        for (int i = cc.length-1; i >= 0; i--) {
            int k = (int) cc[i];
            sum += sum(k);
            add(k, 1);
        }
        System.out.println(sum);
    }

    public static long sum(int i) {
        long sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    public static void add(int i, int v) {
        for (; i < bit.length; i += i&-i) {
            bit[i] += v;
        }
    }
}
