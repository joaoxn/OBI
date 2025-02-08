import java.util.*;

public class toupeira {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        Map<Integer, List<Integer>> rotas = new HashMap<>();

        int s = scan.nextInt();
        int t = scan.nextInt();

        for (int i = 0; i < t; i++) {
            Integer x = scan.nextInt();
            Integer y = scan.nextInt();

            rotas.putIfAbsent(x, new ArrayList<>());
            rotas.putIfAbsent(y, new ArrayList<>());
            rotas.get(x).add(y);
            rotas.get(y).add(x);
        }

        int p = scan.nextInt();
        int[][] passeio = new int[p][];
        for (int i = 0; i < p; i++) {
            int n = scan.nextInt();
            passeio[i] = new int[n];
            for (int j = 0; j < n; j++) {
                passeio[i][j] = scan.nextInt();
            }
        }

        int possiveis = 0;
        PASSEIOS:
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < passeio[i].length-1; j++) {
                int curr = passeio[i][j];
                int next = passeio[i][j+1];

                List<Integer> paths = rotas.get(curr);
                if (paths == null) continue PASSEIOS;
                if (!paths.contains(next)) continue PASSEIOS;
            }
            possiveis++;
        }
        System.out.println(possiveis);
        scan.close();
    }
}
