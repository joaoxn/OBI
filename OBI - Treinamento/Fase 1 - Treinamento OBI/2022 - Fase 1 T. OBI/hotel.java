//
// Created by xnaxg on 01/06/2025.
// Exercício: https://neps.academy/br/exercise/2067
// Resolvido em: 09m:52s
//

import java.util.Scanner;

public class hotel {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int d = scn.nextInt();
        int a = scn.nextInt();
        int n = scn.nextInt()-1;

        int diaria = (d + Math.min(14, n)*a);

        System.out.println((31-n) * diaria);
        scn.close();
    }
}
