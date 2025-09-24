/*
 * Exercício: https://neps.academy/br/exercise/2927
 * Iniciado: 21/09/25 16:30
 * Resolvido em: NÃO RESOLVIDO (16/100)
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class brigadeiros {
    static Scanner scan = new Scanner(System.in);
    static class Prato {
        int p;
        int i;
        public Prato(int p, int i) {
            this.p = p;
            this.i = i;
        }
    }

    public static void main(String[] args) {
        int n = scan.nextInt(); // 1 <= n <= 300
        int k = scan.nextInt(); // tamanho do grupo. 1 <= k <= n
        int t = scan.nextInt(); // 1 <= t <= 10^9

        List<Prato> p = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            p.add(new Prato(scan.nextInt(), i));
        }

        List<Integer> membros = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (scan.nextInt() == 1) membros.add(i);
        }

        List<Prato> pratosPossiveis = new ArrayList<>(p);
        pratosPossiveis.sort((o1, o2) -> o2.p - o1.p);
        List<Prato> pratos;

        int soma = 0;
        while (true) {
            pratos = new ArrayList<>(pratosPossiveis);
            pratos = pratos.subList(0, k);
            pratos.sort((o1, o2) -> o1.i - o2.i);
            
            soma = 0;
            int distTotal = 0;
            double menorMotivo = Integer.MAX_VALUE;
            Prato piorPrato = null;
            for (int i = 0; i < membros.size(); i++) {
                int membro = membros.get(i);
                Prato prato = pratos.get(i);
                int dist = Math.abs(prato.i - membro);
                double motivo = 18;
                for (int membroExt : membros) {
                    int distExt = Math.abs(prato.i - membroExt);
                    double motivoExt = distExt != 0 ? (double) (prato.p)/(distExt) : prato.p*2;
                    if (motivoExt < motivo) motivo = motivoExt;
                }

                distTotal += dist;
                soma += prato.p;
                if (motivo > menorMotivo) continue;
                if (motivo == menorMotivo && piorPrato != null && piorPrato.p < prato.p) continue;

                menorMotivo = motivo;
                piorPrato = prato;
            }
            if (distTotal <= t) break;
            pratosPossiveis.remove(piorPrato);
        }

        System.out.println(soma);
        scan.close();
    }
}

/*
 * 3s
 * 9 9 9 0 1
 * 0 1 0 0 1
 */
