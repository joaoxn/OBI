import com.sun.jdi.request.InvalidRequestStateException;

import java.util.*;

public class PoderMelhorado {
    static Scanner scan = new Scanner(System.in);
    static int n = scan.nextInt();
    static int m = scan.nextInt();

    static int[][] jogo = new int[n][m];
    static List<Integer[]> numeros0JaIterados = new ArrayList<>();

    public static void main(String[] args) {

        int[][] jogoIn = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                jogoIn[i][j] = scan.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                jogo[0] = jogoIn[0].clone();
                jogo[1] = jogoIn[1].clone();
                numeros0JaIterados.clear();

                System.out.print(poderMax(new Heroi(jogo[i][j], i, j))+" ");
            }
            System.out.println();
        }
    }


    public static int poderMax(Heroi heroi) {
        while (true) {
            List<Monstro> monstrosDisponiveis = procurarVitimas(heroi);

            if (monstrosDisponiveis.isEmpty()) return heroi.poder;

            monstrosDisponiveis.forEach((monstro) -> {
                heroi.poder += monstro.poder;
                jogo[monstro.y][monstro.x] = 0;
            });
        }
    }

    public static List<Monstro> procurarVitimas(Heroi heroi) {
        List<Monstro> result = new ArrayList<>();

        List<Integer[]> pos = new ArrayList<>();
        pos.add(new Integer[]{heroi.x, heroi.y+1});
        pos.add(new Integer[]{heroi.x, heroi.y-1});
        pos.add(new Integer[]{heroi.x-1, heroi.y});
        pos.add(new Integer[]{heroi.x+1, heroi.y});
        LOOP:
        for (int i = 0; true; i++) {
            if (i >= pos.size()) break;
            try {
                if (containsArray(numeros0JaIterados, pos.get(i))) continue;
                Monstro monstro = verificarMonstro(pos.get(i)[0], pos.get(i)[1], heroi);
                if (monstro.poder == 0) {
                    numeros0JaIterados.add(pos.get(i));
                    pos.add(new Integer[]{monstro.x, monstro.y+1});
                    pos.add(new Integer[]{monstro.x, monstro.y-1});
                    pos.add(new Integer[]{monstro.x+1, monstro.y});
                    pos.add(new Integer[]{monstro.x-1, monstro.y});
                } else result.add(monstro);
            } catch (InvalidRequestStateException ignore) {} catch (ArrayIndexOutOfBoundsException e) {
//                System.out.println("Catched: " + e);
            }
        }

        return result.stream().distinct().toList();
    }

    public static boolean containsArray(List<Integer[]> matrix, Integer[] array) {
        for (Integer[] arrKey : matrix) {
            if (Objects.equals(arrKey[0], array[0]) && Objects.equals(arrKey[1], array[1])) return true;
        }
        return false;
    }

    public static Monstro verificarMonstro(int x, int y, Heroi heroi) {
        Monstro monstro = new Monstro(jogo[y][x], x, y);
        if (monstro.poder > heroi.poder || monstro.x == heroi.x && monstro.y == heroi.y) {
            throw new InvalidRequestStateException();
        }
        return monstro;
    }
}

class Monstro {
    int poder;
    int x;
    int y;

    public Monstro(int poder, int x, int y) {
        this.poder = poder;
        this.x = x;
        this.y = y;
    }
}

//class Heroi {
//    int poder;
//    int x;
//    int y;
//
//    int top = 1000000001;
//    int bottom = 1000000001;
//    int left = 1000000001;
//    int right = 1000000001;
//
//    public Heroi(int poder, int x, int y) {
//        this.poder = poder;
//        this.x = x;
//        this.y = y;
//    }
//}
