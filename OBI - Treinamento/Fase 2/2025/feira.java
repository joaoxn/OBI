/*
 * Iniciado: 08/2025 22:12
 * Resolvido em: 08/2025 23:32 (1h07m)
 */

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class feira {
    static class Objeto {
        int tipo;
        int preco;
        int index;
        boolean vendido = false;
        Objeto(int tipo, int index) {
            this.tipo = tipo;
            this.index = index;
        }
    }
    static Scanner scan = new Scanner(System.in);
    static int n;
    static int t;
    static HashMap<Integer, LinkedList<Objeto>> tipos = new HashMap<>();
    static LinkedList<Objeto> objs = new LinkedList<>();

    static int c;
    static int[] clientes;

    public static void main(String[] args) {
        n = scan.nextInt();
        t = scan.nextInt();
        
        for (int i = 0; i < n; i++) {
            int tipo = scan.nextInt();
            Objeto obj = new Objeto(tipo, i);
            objs.add(obj);
            tipos.putIfAbsent(tipo, new LinkedList<>());
            tipos.get(tipo).add(obj);
        }

        for (int i = 0; i < n; i++) {
            objs.get(i).preco = scan.nextInt();
        }

        sort(objs);
        
        for (int i = 1; i <= t; i++) {
            LinkedList<Objeto> list = tipos.get(i);
            if (list == null) continue;
            sort(list);
        }

        c = scan.nextInt();
        clientes = new int[c];
        for (int i = 0; i < c; i++) {
            clientes[i] = scan.nextInt();
        }

        System.out.println(solve());
    }
    public static void sort(LinkedList<Objeto> list) {
        list.sort(feira::sort);
    }
    private static int sort(Objeto o1, Objeto o2) {
        int comp = Integer.compare(o1.preco, o2.preco);
        if (comp == 0) comp = Integer.compare(o1.tipo, o2.tipo);
        return comp;
    }

    public static long solve() {
        long total = 0;
        for (int i = 0; i < c; i++) {
            int cliente = clientes[i];
            
            Objeto obj = null;
            if (cliente == 0) {
                do {
                    obj = objs.poll();
                } while (obj != null && obj.vendido);
            } else {
                LinkedList<Objeto> list = tipos.get(cliente);
                if (list != null) {
                    do {
                        obj = list.poll();
                    } while (obj != null && obj.vendido);
                }
            }
            if (obj == null) continue;
            
            total += obj.preco;
            obj.vendido = true;
        }

        return total;
    }
}
