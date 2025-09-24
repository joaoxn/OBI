/*
 * Exercício: https://neps.academy/br/exercise/337
 * Iniciado: 13/09/25 22:00
 * Resolvido em: 14/09/25 10:17 (29m)
 */

import java.util.*;

public class hanoi {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        ArrayList<Integer> ns = new ArrayList<>();

        while (true) {
            int n = scan.nextInt();
            if (n == 0) break;
            ns.add(n);
        }

        for (int i = 0; i < ns.size(); i++) {
            int n = ns.get(i);
            System.out.println("Teste "+(i+1));
            int total = 1;
            for (int j = 2; j <= n; j++) {
                total = total*2 + 1;
            }
            System.out.println(total);
            System.out.println();
        }
    }
}

/*
 * hanoi(3)
 *  hanoi(2)
 *      hanoi(1)
 *      hanoi(1)
 *  hanoi(2)
 *      hanoi(1)
 *      hanoi(1)
 * 
 * hanoi(2)
 * 
 */

