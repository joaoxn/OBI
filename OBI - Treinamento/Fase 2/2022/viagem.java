import java.util.*;

public class viagem {

    static class Rota {
        public int tempo;
        public int custo;
        public int destino;

        public Rota(int tempo, int custo, int destino) {
            this.tempo = tempo;
            this.custo = custo;
            this.destino = destino;
        }
    }

    private static final Map<Integer, List<Rota>> rotas = new HashMap<>();

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int v = scan.nextInt();
        int n = scan.nextInt();
        int m = scan.nextInt();

        for (int i = 0; i < m; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            int t = scan.nextInt();
            int p = scan.nextInt();
            Rota rotaParaB = new Rota(t, p, b);
            Rota rotaParaA = new Rota(t, p, a);

            rotas.putIfAbsent(a, new ArrayList<>());
            rotas.putIfAbsent(b, new ArrayList<>());

            rotas.get(a).add(rotaParaB);
            rotas.get(b).add(rotaParaA);
        }

        int x = scan.nextInt();
        int y = scan.nextInt();

        scan.close();

        System.out.println(search(x, y, v, 0, new ArrayList<>()));
    }
    public static int search(int x, int y, int teto, int tempo, List<Integer> rotasPassadas) {
        if (x == y) return tempo;
        List<Rota> caminhos = rotas.get(x);

        for (int i = caminhos.size()-1; i >= 0; i--) {
            Rota caminho = caminhos.get(i);
            if (rotasPassadas.contains(caminho.destino)
                    || teto - caminho.custo < 0)
                caminhos.remove(i);
        }

        int[] results = new int[caminhos.size()];
        for (int i = 0; i < caminhos.size(); i++) {
            Rota caminho = caminhos.get(i);
            rotasPassadas.add(x);
            results[i] = search(caminho.destino, y,
                    teto - caminho.custo,
                    tempo + caminho.tempo, rotasPassadas);
        }
        int best = Integer.MAX_VALUE;
        boolean noResults = true;
        for (int result : results) {
            if (result == -1) continue;
            noResults = false;
            if (result < best) best = result;
        }
        rotasPassadas.remove(Integer.valueOf(x));
        return noResults ? -1 : best;
    }
}
