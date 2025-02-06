import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class lista {
    public static List<Integer> lista;

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        lista = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            lista.add(scn.nextInt());
        }
        boolean changed;
        int additions = 0;
        do {
            changed = false;
            for (int i = 0; i < lista.size(); i++) {
                int num = lista.get(i);
                int oppNum = lista.get(lista.size() - i - 1);
                if (num == oppNum) continue;
                if (num < oppNum) {
                    //add num
                    addNums(i, num);
                } else {
                    // add oppNum
                    addNums(lista.size() - i - 1, oppNum);
                }
                changed = true;
                additions++;
            }
        } while (changed);
        System.out.println(additions);
    }

    public static void addNums(int i, int num) {
        Boolean isPerfect = isPerfect(i+1);
        if (isPerfect == null || isPerfect && isPerfect(i-1) != null) {
            // take the one before it
            lista.set(i, num + lista.get(i-1));
            lista.remove(i-1);
        } else {
            // take the one after it
            lista.set(i, num + lista.get(i+1));
            lista.remove(i+1);
        }
    }

    public static Boolean isPerfect(int i) {
        int oppI = lista.size() - i - 1;
        if (i == oppI) return false;
        try {
            return (int) lista.get(i) == lista.get(oppI);
        } catch (Exception e) {
            return null;
        }
    }
}
