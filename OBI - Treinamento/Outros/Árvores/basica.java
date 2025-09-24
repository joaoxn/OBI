
/*
* 4
* 1 2
* 1 3
* 3 4
* 3 5
*/

import java.util.*;

public class basica {
    static Scanner scan = new Scanner(System.in);
    static Map<Integer, List<Integer>> map = new HashMap<>();
    public static void main(String[] args) {
        int n = scan.nextInt();
        int head = 0;

        for (int i = 0; i < n; i++) {
            int k = scan.nextInt();
            int v = scan.nextInt();
            if (i == 0) head = k;
            map.putIfAbsent(k, new ArrayList<>());
            map.get(k).add(v);
        }

        int node = head;
        System.out.println(dfs(node));
    }

    public static int dfs(int node) {
        int sum = node;
        List<Integer> children = map.get(node);
        if (children == null || children.isEmpty()) return sum;
        for (Integer child : children) {
            sum += dfs(child);
        }
        return sum;
    }
}
