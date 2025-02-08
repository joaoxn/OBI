import java.util.Scanner;

public class trofeu {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int[] notas = new int[5];
        for (int i = 0; i < 5; i++) {
            notas[i] = scan.nextInt();
        }
        int trofeus = 1;
        int notaTrofeu = notas[0];
        int placas = 0;
        int notaPlaca = 0;

        for (int i = 1; i < 5; i++) {
            if (notas[i] != notas[i-1]) {
                if (notaPlaca == 0) {
                    notaPlaca = notas[i];
                    placas++;
                }
                continue;
            }
            if (notaPlaca == 0 && notas[i] == notaTrofeu)
                trofeus++;
            else if (notas[i] == notaPlaca)
                placas++;
        }
        System.out.println(trofeus);
        System.out.println(placas);
    }
}
