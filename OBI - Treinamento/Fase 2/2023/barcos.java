import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class barcos {
    static Scanner scan = new Scanner(System.in);
    static int ilhasQtd = scan.nextInt();
    static int barcosQtd = scan.nextInt();
    static int[][] trajetos = new int[barcosQtd][3];

    public static void main(String[] args) {
        for (int i = 0; i < barcosQtd; i++)
            for (int j = 0; j < 3; j++)
                trajetos[i][j] = scan.nextInt();

        int consultasQtd = scan.nextInt();
        int[][] consultas = new int[consultasQtd][2];

        for (int i = 0; i < consultasQtd; i++) {
            for (int j = 0; j < 2; j++)
                consultas[i][j] = scan.nextInt();
        }
        for (int[] consulta : consultas)
            System.out.println(maxPassageiros(consulta));
    }

    private static int maxPassageiros(int[] consulta) {
        int ilhaInicio = consulta[0];
        int ilhaFim = consulta[1];

        List<int[]> qualquerCoisa = new ArrayList<>();
        List<int[]> trajetosAtual = new ArrayList<>(Arrays.stream(trajetos).toList());
        int ilhaAtual = ilhaInicio;
        while (!(ilhaAtual == ilhaFim)) {
            int[] trajeto = viajar(ilhaAtual, trajetosAtual);
            if (trajeto[0] == -1) {
                trajetosAtual = new ArrayList<>(Arrays.stream(trajetos).toList());
                ilhaAtual = qualquerCoisa.get(qualquerCoisa.size() - 1)[Math.random() < 0.5 ? 0 : 1]; //TODO: trocar aleatório por algo melhor
                continue;
            }
            trajetosAtual.remove(trajeto);
            qualquerCoisa.add(trajeto);
            ilhaAtual = trajeto[0] == ilhaAtual ? trajeto[1] : trajeto[0];
        }
        int passageirosMax = qualquerCoisa.get(0)[2];
        for (int[] max : qualquerCoisa) {
            passageirosMax = Math.min(max[2], passageirosMax);
        }

        return passageirosMax;
    }

    private static int[] viajar(int ilhaPartida, List<int[]> trajetosIn) {
        List<int[]> trajetosInicial = trajetosIn.stream().filter((trajeto) -> trajeto[0] == ilhaPartida || trajeto[1] == ilhaPartida).toList();
        if (trajetosInicial.isEmpty()) {
            return new int[]{-1};
        }
        int passageirosMax = trajetosInicial.get(0)[2];
        int[] rota = trajetosInicial.get(0);
        for (int[] trajeto : trajetosInicial)
            if (trajeto[2] > passageirosMax) {
                passageirosMax = trajeto[2];
                rota = trajeto;
            }
        return trajetosInicial.stream().reduce((trajeto, maior) -> trajeto[2] > maior[2] ? trajeto : maior).orElseThrow();
    }
}