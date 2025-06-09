import java.util.Arrays;
import java.util.Scanner;

public class grupos {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int estudantes = scan.nextInt();
        int[][] paresbom = new int[scan.nextInt()][2];
        int[][] paresruim = new int[scan.nextInt()][2];
        int restricoes = 0;

        for (int i = 0; i < paresbom.length; i++)
            for (int j = 0; j < 2; j++)
                paresbom[i][j] = scan.nextInt();

        for (int i = 0; i < paresruim.length; i++)
            for (int j = 0; j < 2; j++)
                paresruim[i][j] = scan.nextInt();

        int[][] grupos = new int[estudantes/3][3];
        for (int i = 0; i < grupos.length; i++)
            for (int j = 0; j < 3; j++)
                grupos[i][j] = scan.nextInt();

        for (int[] grupo : grupos) {
            for (int[] pares : paresbom)
                if (!contains(grupo, pares[0]) && !contains(grupo, pares[1]))
                    restricoes++;
            for (int[] pares : paresruim)
                if (contains(grupo, pares[0]) && contains(grupo, pares[1]))
                    restricoes++;
        }

        System.out.println(restricoes);
     }

     private static boolean contains(int[] array, int key) {
        for (int num : array)
            if (num == key) return true;
        return false;
     }
}
