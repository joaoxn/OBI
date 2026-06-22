import java.util.Arrays;
import java.util.Scanner;

public class concurso {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        //todo: maior nota C que faz com que no mínimo K candidatos sejam aprovados.

        int qtdCandidatos = scan.nextInt();
        int minimoCandidatos = scan.nextInt();
        int[] notas = new int[qtdCandidatos];
        for (int i = 0; i < qtdCandidatos; i++) {
            notas[i] = scan.nextInt();
        }

        Arrays.sort(notas);
        System.out.println(notas[notas.length - minimoCandidatos]);
    }
}
