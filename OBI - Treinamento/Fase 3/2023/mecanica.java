import java.util.Arrays;
import java.util.Scanner;

public class mecanica {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(), m = scn.nextInt();
        int[] tempos = new int[n];
        int[] fatores = new int[m];

        for (int i = 0; i < n; i++) {
            tempos[i] = scn.nextInt();
        }
        for (int j = 0; j < m; j++) {
            fatores[j] = scn.nextInt();
        }

        Arrays.sort(tempos);
        Arrays.sort(fatores);

        for (int i = 0; i < fatores.length/2; i++) {
            int j = fatores.length-i-1;
            int temp = fatores[i];
            fatores[i] = fatores[j];
            fatores[j] = fatores[i];
        }

        int soma = 0;
        for (int i = 0; i < n && i < m; i++) {
//                System.out.print(Arrays.toString(tempos));
//                System.out.print("  "+Arrays.toString(fatores));
//                System.out.print("  "+tempos[i*i-1]);
//                System.out.print("  "+fatores[i-1]);
//                System.out.println("  "+(n/m-i));
                soma += tempos[i] * fatores[i];
        }
        System.out.println(soma);
    }

    static class Mechanic implements Comparable<Mechanic> {
        int currentTime;
        int factor;

        public Mechanic(int currentTime, int factor) {
            this.currentTime = currentTime;
            this.factor = factor;
        }


        @Override
        public int compareTo(Mechanic o) {
            return Integer.compare(this.currentTime, o.currentTime);
        }
    }
}
