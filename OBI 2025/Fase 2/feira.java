/*
 * 67/100 Pontos - Falhas na Subtarefa 7 e 8.
 * Subtarefa 7: Tempo de execução excedido;
 * Subtarefa 8: Tempo de execução excedido.
 */

import java.util.*;

public class feira {
    public static class Objeto {
        int tipo;
        int preco;
        int index;
        boolean vendido = false;

        Objeto(int tipo, int preco, int index) {
            this.tipo = tipo;
            this.preco = preco;
            this.index = index;
        }
    }

    static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scan.nextInt();
        int t = scan.nextInt();

        int[] tipos = new int[n];
        for (int i = 0; i < n; i++) {
            tipos[i] = scan.nextInt();
        }

        Objeto[] objs = new Objeto[n];
        for (int i = 0; i < n; i++) {
            int preco = scan.nextInt();
            objs[i] = new Objeto(tipos[i], preco, i);
        }

        Comparator<Objeto> globalComp = (a, b) -> {
            int c = Integer.compare(a.preco, b.preco);
            if (c != 0) return c;
            c = Integer.compare(a.tipo, b.tipo);
            if (c != 0) return c;
            return Integer.compare(a.index, b.index);
        };

        Comparator<Objeto> perTipoComp = (a, b) -> {
            int c = Integer.compare(a.preco, b.preco);
            if (c != 0) return c;
            return Integer.compare(a.index, b.index);
        };

        TreeSet<Objeto> global = new TreeSet<>(globalComp);
        @SuppressWarnings("unchecked")
        TreeSet<Objeto>[] byTipo = new TreeSet[t + 1];

        for (Objeto o : objs) {
            if (byTipo[o.tipo] == null) byTipo[o.tipo] = new TreeSet<>(perTipoComp);
            byTipo[o.tipo].add(o);
            global.add(o);
        }

        int c = scan.nextInt();
        long total = 0L;
        for (int i = 0; i < c; i++) {
            int cliente = scan.nextInt();

            if (cliente == 0) {
                if (global.isEmpty()) continue;
                Objeto escolhido = global.pollFirst();
                TreeSet<Objeto> s = byTipo[escolhido.tipo];
                if (s != null) s.remove(escolhido);
                total += escolhido.preco;
            } else {
                if (cliente < 1 || cliente > t) continue;
                TreeSet<Objeto> s = byTipo[cliente];
                if (s == null || s.isEmpty()) continue;
                Objeto escolhido = s.pollFirst();
                global.remove(escolhido);
                total += escolhido.preco;
            }
        }

        System.out.println(total);
    }
}
