import java.util.Arrays;
import java.util.Scanner;

public class frutasOld {
    static Scanner scn = new Scanner(System.in);
    static int r = scn.nextInt();
    static int n = scn.nextInt();
    static int[] frutasT = new int[n];
    static int[] frutasP = new int[n];

    public static void main(String[] args) {
        for (int i = 0; i < n; i++) {
//            System.out.println(Arrays.toString(frutasT) + " " + Arrays.toString(frutasP));
            int tipo = scn.nextInt();
            int preco = scn.nextInt();
            int search = indexOf(frutasT, tipo);
            if (search > -1) {
                if (frutasP[search] > preco)
                    frutasP[search] = preco;
                i--;
                n--;
                continue;
            }
            frutasT[i] = tipo;
            frutasP[i] = preco;
        }
        System.out.println(frutasMax());
    }

    public static int frutasMax() {
        frutasP = Arrays.copyOf(frutasP, n);
        Arrays.sort(frutasP);
        for (int i = 0; i < n;) {
            if (r <= 0 || r < frutasP[i]) return i;
            r -= frutasP[i];
            i++;
        }
        return frutasP.length;
    }

    public static int indexOf(int[] arr, int key) {
        int res = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key) {
                res = key;
                break;
            }
        }
        return res;
    }
}