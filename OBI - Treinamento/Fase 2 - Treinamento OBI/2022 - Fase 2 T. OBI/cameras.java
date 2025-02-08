import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class cameras {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int m = scan.nextInt();
        int k = scan.nextInt();

        boolean[][] quadro = new boolean[n][m];

        for (int i = 0; i < k; i++) {
            int c = scan.nextInt()-1;
            int l = scan.nextInt()-1;
            char d = scan.next().charAt(0);

            visivel(quadro, c, l, d);
        }
        boolean result = search(quadro, 0, 0);

        System.out.println(result ? 'S' : 'N');

        scan.close();
    }
    public static void visivel(boolean[][] quadro, int c, int l, char d) {
        quadro[c][l] = true;
        switch (d) {
            case 'N':
                l -= 1;
                break;
            case 'S':
                l += 1;
                break;
            case 'L':
                c += 1;
                break;
            case 'O':
                c -= 1;
                break;
        }
        if (!isInBounds(quadro, c, l)) return;
        visivel(quadro, c, l, d);
    }

    private static final List<Integer> colunasViajadas = new ArrayList<>();
    private static final List<Integer> linhasViajadas = new ArrayList<>();
    public static boolean search(boolean[][] quadro, int c, int l) {
        if (c == quadro.length-1 && l == quadro[c].length-1)
            return true;

        colunasViajadas.add(c);
        linhasViajadas.add(l);

        List<Integer> colDirections = new ArrayList<>();
        List<Integer> lineDirections = new ArrayList<>();

        if (isInBounds(quadro, c, l-1) && !quadro[c][l-1]
                && !hasBeenVisited(c, l-1)) {
            colDirections.add(c);
            lineDirections.add(l-1);
            System.out.println(c + ", " + (l-1) + " é trafegável");
        } else {
            System.out.println(c + ", " + (l-1) + " não trafegável");
        }

        if (isInBounds(quadro, c, l+1) && !quadro[c][l+1]
                && !hasBeenVisited(c, l+1)) {
            colDirections.add(c);
            lineDirections.add(l+1);
            System.out.println(c + ", " + (l+1) + " é trafegável");
        } else {
            System.out.println(c + ", " + (l+1) + " não trafegável");
        }

        if (isInBounds(quadro, c-1, l) && !quadro[c-1][l]
                && !hasBeenVisited(c-1, l)) {
            colDirections.add(c-1);
            lineDirections.add(l);
            System.out.println((c-1) + ", " + l + " é trafegável");
        } else {
            System.out.println((c-1) + ", " + l + " não trafegável");
        }

        if (isInBounds(quadro, c+1, l) && !quadro[c+1][l]
                && !hasBeenVisited(c+1, l)) {
            colDirections.add(c+1);
            lineDirections.add(l);
            System.out.println((c+1) + ", " + l + " é trafegável");
        } else {
            System.out.println((c+1) + ", " + l + " não trafegável");
        }

        if (colDirections.isEmpty())
            return false;

        for (int i = 0; i < colDirections.size(); i++) {
            System.out.println("Movendo para célula: "+ colDirections.get(i) +", "+ lineDirections.get(i));
            boolean result = search(quadro, colDirections.get(i), lineDirections.get(i));
            if (result) return true;
            System.out.println("Caminho sem saída... Voltando");
        }
        return false;
    }
    public static boolean isInBounds(boolean[][] quadro, int c, int l) {
        return !(c < 0 || l < 0 || c >= quadro.length || l >= quadro[c].length);
    }
    public static boolean hasBeenVisited(int c, int l) {
        for (int i = 0; i < colunasViajadas.size(); i++) {
            if (colunasViajadas.get(i) == c && linhasViajadas.get(i) == l)
                return true;
        }
        return false;
    }
}
