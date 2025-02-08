import java.util.Arrays;
import java.util.Scanner;

public class cifra {
    public static void main(String[] args) {
        char[] consonants =     "bcdfghjklmnpqrstvxz".toCharArray();
        char[] closestVogals =  "aaeeeiiiiooooouuuuu".toCharArray();
        Scanner scan = new Scanner(System.in);

        String input = scan.next();

        // Iteração entre todos os caracteres da entrada
        for (char character : input.toCharArray()) {
            // Primeira letra sempre é exibida
            System.out.print(character);

            // Pesquisa a posição do caractere no array consonants
            // Retorna valor negativo se não encontrado
            int consonantPos = Arrays.binarySearch(consonants, character);

            // Se for positivo pertence ao array consonants e é uma consoante
            if (consonantPos >= 0 && consonantPos < consonants.length) {
                System.out.print(closestVogals[consonantPos]);
                System.out.print(consonants[(consonantPos+1) == consonants.length ? consonantPos : consonantPos+1]);
            }
        }
        System.out.println();
    }
}