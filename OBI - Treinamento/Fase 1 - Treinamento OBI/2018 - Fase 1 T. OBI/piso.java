import java.util.Scanner;

public class piso {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int x = scan.nextInt();
        int y = scan.nextInt();

        int t1 = x*y + (x-1)*(y-1); // Área de t1 = 0.5
        double areaRestante = x*y - (t1+1)*0.5;
        int t2 = (int) (areaRestante*4);

        System.out.println(areaRestante);
        System.out.println(t1);
        System.out.println(t2);
    }
}
