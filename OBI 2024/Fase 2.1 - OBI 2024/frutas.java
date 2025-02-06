import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class frutas {
    static Scanner scn = new Scanner(System.in);
    static int r = scn.nextInt();
    static int n = scn.nextInt();
    static Map<Integer, Integer> frutasMap = new HashMap<>();

    public static void main(String[] args) {
        for (int i = 0; i < n; i++) {
//            System.out.println(Arrays.toString(frutasT) + " " + Arrays.toString(frutasP));
            int tipo = scn.nextInt();
            int preco = scn.nextInt();

            if (frutasMap.containsKey(tipo)) {
                frutasMap.put(tipo, Math.min(frutasMap.get(tipo), preco));
            } else {
                frutasMap.put(tipo, preco);
            }
        }
        System.out.println(frutasMax());
    }

    public static int frutasMax() {
        int[] precos = frutasMap.values().stream().mapToInt(Integer::intValue).toArray();
        Arrays.sort(precos);
        int result = 0;
        for (int preco : precos) {
            if (r < preco) break;
            r -= preco;
            result++;
        }
        return result;
    }
}