import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class poder {
    static Scanner scan = new Scanner(System.in);
    static int n = scan.nextInt();
    static int m = scan.nextInt();

    static int[][] jogo = new int[n][m];

    static public List<Integer[]> historyOfPos = new ArrayList<>();

    public static void main(String[] args) {

        int[][] jogoIn = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                jogoIn[i][j] = scan.nextInt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                jogo = jogoIn;
                System.out.println(poderMax(new Heroi(jogo[i][j], i, j)));
            }
        }
    }


    public static int poderMax(Heroi heroi) {
        while(true) {
            heroi.poder = jogo[heroi.y][heroi.x];

            heroi.top = heroi.y + 1 >= jogo.length ? 1000000001 : jogo[heroi.y + 1][heroi.x];
            heroi.bottom = heroi.y - 1 < 0 ? 1000000001 : jogo[heroi.y - 1][heroi.x];
            heroi.left = heroi.x - 1 < jogo.length ? 1000000001 : jogo[heroi.y][heroi.x - 1];
            heroi.right = heroi.x + 1 >= jogo.length ? 1000000001 : jogo[heroi.y][heroi.x + 1];

            int top = heroi.top;
            int bottom = heroi.bottom;
            int left = heroi.left;
            int right = heroi.right;

            if (top > heroi.poder)
                top = -1;
            if (bottom > heroi.poder)
                bottom = -1;
            if (left > heroi.poder)
                left = -1;
            if (right > heroi.poder)
                right = -1;

            int max = Math.max(Math.max(top, bottom), Math.max(left, right));

            if (max == heroi.top)
                mover(heroi.x, heroi.y + 1, heroi);
            else if (max == heroi.bottom)
                mover(heroi.x, heroi.y - 1, heroi);
            else if (max == heroi.left)
                mover(heroi.x - 1, heroi.y, heroi);
            else if (max == heroi.right)
                mover(heroi.x + 1, heroi.y, heroi);
            else return heroi.poder;
        }
    }

    public static void mover(int x, int y, Heroi heroi) {
        jogo[y][x] = heroi.poder + jogo[y][x];
        jogo[heroi.y][heroi.x] = 0;
    }
}

class Heroi {
    int poder;
    int x;
    int y;

    int top = 1000000001;
    int bottom = 1000000001;
    int left = 1000000001;
    int right = 1000000001;

    Heroi(int poder, int x, int y) {
        this.poder = poder;
        this.x = x;
        this.y = y;
    }
}
