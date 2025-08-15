//
// Created by xnaxg on 01/06/2025.
// Exercício: https://neps.academy/br/exercise/2070
// Resolvido em: 11m:39s
//


import java.util.Scanner;

public class bombom {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String _str = scan.next();
        char dominante = _str.charAt(1);

        int luana = 0;
        int edu = 0;

        for (int i = 0; i < 6; i++) {
            String str = scan.next();
            char fig = str.charAt(0);
            char naipe = str.charAt(1);

            if (i < 3)
                luana += value(fig, naipe == dominante);
            else
                edu += value(fig, naipe == dominante);
        }

        if (luana > edu) {
            System.out.println("Luana");
        } else if (luana < edu) {
            System.out.println("Edu");
        } else {
            System.out.println("empate");
        }
        scan.close();
    }

    public static int value(char fig, boolean dominante) {
        int value;
        if (fig == 'A') value = 10;
        else if (fig == 'J') value = 11;
        else if (fig == 'Q') value = 12;
        else value = 13;

        return value + (dominante ? 4 : 0);
    }
}
