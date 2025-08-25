import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class distinto {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        List<Integer> nums = new ArrayList<>();

        int length = scan.nextInt();
        for (int i = 0; i < length; i++)
            nums.add(scan.nextInt());

        List<List<Integer>> sequencias = new ArrayList<>();
        sequencias.add(new ArrayList<>());
        for (int i = 0; i < nums.size(); i++) {
            List<Integer> seqAtual = sequencias.get(sequencias.size() - 1);
            int containsAt = containsAtPos(seqAtual, nums.get(i));
            if (containsAt == -1) seqAtual.add(nums.get(i));
            else sequencias.add(seqAtual);
        }
        System.out.println(biggestListSize(sequencias));
        scan.close();
    }

    private static int containsAtPos(List<Integer> list, int key) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) == key) return i;
        }
        return -1;
    }

    private static int biggestListSize(List<List<Integer>> list) {
        int biggestSize = 0;
        for (List<Integer> innerList : list)
            if (innerList.size() > biggestSize) biggestSize = innerList.size();
        return biggestSize;
    }
}
