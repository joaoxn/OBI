import java.util.*;

public class transportes2 {
    static Map<Integer, List<transportes.Ligacao>> estacoes = new HashMap<>();
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt(), m = scan.nextInt(), k = scan.nextInt();

        int[] precos = new int[k];
        for (int i = 0; i < k; i++)
            precos[i] = scan.nextInt();

        for (int i = 0; i < m; i++) {
            int v = scan.nextInt();
            int u = scan.nextInt();
            int t = scan.nextInt();
            estacoes.putIfAbsent(v, new ArrayList<>());
            estacoes.putIfAbsent(u, new ArrayList<>());
            estacoes.get(v).add(new transportes.Ligacao(u, t));
            estacoes.get(u).add(new transportes.Ligacao(v, t));
        }
        int a = scan.nextInt();
        int b = scan.nextInt();

        int valor = viajar(a, b, null);
        if (valor == 1001) System.out.println(-1);
        else System.out.println(valor);
    }
    public static int viajar(int a, int b, Integer c) {
        return 10;
    }
}
