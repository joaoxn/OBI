import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class lista {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        List<Long> lista = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            lista.add(scn.nextLong());
        }
        int i = 0, j = lista.size() - 1;
        int additions = 0;
        while (i < j) {
            long left = lista.get(i);
            long right = lista.get(j);
            if (left == right) {
                i++;
                j--;
            } else if (left < right) {
                // Mescla o elemento da esquerda com o próximo
                lista.set(i + 1, left + lista.get(i + 1));
                i++;
                additions++;
            } else {
                // Mescla o elemento da direita com o anterior
                lista.set(j - 1, right + lista.get(j - 1));
                j--;
                additions++;
            }
        }
        System.out.println(additions);
        scn.close();
    }
}
