import java.util.*;

public class transportes {
    static int[] precos;
    static Map<Integer, List<Ligacao>> estacoes = new HashMap<>();

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int k = scn.nextInt();

        precos = new int[k + 1];
        for (int i = 1; i <= k; i++) {
            precos[i] = scn.nextInt();
        }

        for (int i = 0; i < m; i++) {
            int v = scn.nextInt();
            int u = scn.nextInt();
            int t = scn.nextInt();
            estacoes.putIfAbsent(v, new ArrayList<>());
            estacoes.putIfAbsent(u, new ArrayList<>());
            estacoes.get(v).add(new Ligacao(u, t));
            estacoes.get(u).add(new Ligacao(v, t));
        }
        int a = scn.nextInt();
        int b = scn.nextInt();

        int valor = viajar(a, b, null);
        if (valor == 1001) System.out.println(-1);
        else System.out.println(valor);
    }

    private static int viajar(int a, int b, List<Integer> estacoesIgnorar) {
        List<Ligacao> ligas = estacoes.get(a);
        List<Ligacao> viagemDireta = new ArrayList<>();
        if (estacoesIgnorar == null)
            estacoesIgnorar = new ArrayList<>();
        estacoesIgnorar.add(a);
        for (int i = 0; i < ligas.size(); i++) {
            if (estacoesIgnorar.contains(ligas.get(i).estacao)) {
                ligas.remove(ligas.get(i));
                i--;
            }
        }

        for (Ligacao ligacao : ligas) {
            // Procura por ligação direta
            if (ligacao.estacao == b) //TODO: Adicionar break
                viagemDireta.add(ligacao);
        }

        if (!viagemDireta.isEmpty()) {
            int smallest = 1001;
            for (Ligacao ligacao : viagemDireta) {
                if (ligacao.valor < smallest) smallest = ligacao.valor;
            }
            return smallest;
        }

        int smallest = 2001;
        // Não existe viagem direta, utilizando backtracking
        for (int i = 0; i < ligas.size(); i++) {
            System.out.println("Viagem interna no."+ i+1 +": " + ligas.get(i).estacao + " para "+ b);
            int valorTransporteDireto = ligas.get(i).valor;
            int res = viajar(ligas.get(i).estacao, b, cloneList(estacoesIgnorar));
            System.out.println("Valor: "+ res + ", Valor total Local: "+ valorTransporteDireto + res);
            if (res + valorTransporteDireto < smallest) {
                smallest = res + valorTransporteDireto;
            }
        }
        return smallest;
    }

    private static List<Integer> cloneList(List<Integer> estacoesIgnorar) {
        return new ArrayList<>(estacoesIgnorar);
    }

    static class Ligacao {
        int estacao;
        int transporte;
        int valor;

        public Ligacao(int estacao, int transporte) {
            this.estacao = estacao;
            this.transporte = transporte;
            this.valor = precos[transporte];
        }

        public Ligacao(int valor) {
            this.valor = valor;
        }
    }
}
