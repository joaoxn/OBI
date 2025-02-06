import java.util.Scanner;

public class relogio {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int horas = scan.nextInt();
        int minutos = scan.nextInt();
        int segundos = scan.nextInt();

        int adiantamento = scan.nextInt();

        segundos += adiantamento;
        if (segundos >= 60) {
            int loops = segundos / 60;
            minutos += loops;
            segundos -= 60*loops;
        }
        if (minutos >= 60) {
            int loops = minutos / 60;
            horas += loops;
            minutos -= 60*loops;
        }

        horas %= 24;

        System.out.println(horas);
        System.out.println(minutos);
        System.out.println(segundos);
    }
}
