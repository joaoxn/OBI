import java.util.Scanner;

public class alfabeto {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int k = scan.nextInt();
        int n = scan.nextInt();

        String alfabeto = scan.next();
        String mensagem = scan.next();

        char saida = 'S';

        for (char letra : mensagem.toCharArray()) {
            if (alfabeto.indexOf(letra) == -1) {
                saida = 'N';
                break;
            }
        }
        System.out.println(saida);
    }
}
