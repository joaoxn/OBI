
import java.util.*;

public class construtora {
    static Scanner scn = new Scanner(System.in);
    static int n = scn.nextInt();
    static int[] a = new int[n];
    static int fases = 0;
    public static void main(String[] args) {
        for (int i = 0; i < n; i++) {
            a[i] = scn.nextInt();
        }
        if (!completed()) {
            while (!fase()) {
                // System.out.println(Arrays.toString(a));
            }
        }
        System.out.println(fases);
    }

    public static boolean completed() {
        int target = a[0];
        for (int num : a) {
            if (num != target) {
                return false;
            }
        }
        return true;
    }

    public static boolean fase() {
        fases++;
        boolean result = true;
        int min = 1000001;
        int idxFirst = 0;
        
        for (int i = 0; i < a.length; i++) {
            if (a[i] < min) {
                min = a[i];
                idxFirst = i;
            }
        }

        a[idxFirst]++;
        // int idxLast = 0;

        for (int i = idxFirst+1; i < a.length; i++) {
            int elem = a[i];
            int prevElem = a[i-1]-1;
            if (elem == prevElem && a[i] == min) {
                a[i]++;
            } else {
                for (int j = i; j < a.length; j++) {
                    if (a[j] != min+1) result = false;
                }
                for (int j = idxFirst-1; j >= 0; j--) {
                    if (a[j] != min+1) result = false;
                }
                break;
            }
        }

        // for (int i = idxFirst; i <= idxLast; i++) {
        //     a[i]++;
        // }

        return result;
    }
}
