import java.util.Arrays;
import java.util.Scanner;

public class jogo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String[] jogo = new String[scan.nextInt()];
        int passos = scan.nextInt();

        for (int i = 0; i < jogo.length; i++)
            jogo[i] = scan.next();

        for (int i = 0; i < passos; i++)
            jogo = passo(jogo);

        for (String linha : jogo)
            System.out.println(linha);
    }

    private static String[] passo(String[] jogoIn) {
        String[] jogo = jogoIn.clone();
        for (int i = 0; i < jogo.length; i++) {
            for (int j = 0; j < jogo[i].length(); j++) {
                StringBuilder linha = new StringBuilder(jogo[i]);
                char celula = linha.charAt(j);
                int vizinhos = procurarVizinhos(jogoIn, i, j);
                if (celula == '0' && vizinhos == 3) linha.setCharAt(j, '1');
                else if (celula == '1' && vizinhos < 2 || vizinhos > 3) linha.setCharAt(j, '0');
                jogo[i] = linha.toString();
            }
        }
        return jogo;
    }

    private static int procurarVizinhos(String[] jogo, int linha, int coluna) {
        int vizinhos = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0 || linha + i < 0 || coluna + j < 0 ||
                        linha + i >= jogo.length || coluna + j >= jogo.length)
                    continue;
                if (jogo[linha + i].charAt(coluna + j) == '1') vizinhos++;
            }
        }
        return vizinhos;
    }
}
