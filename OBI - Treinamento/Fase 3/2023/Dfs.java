import java.security.KeyPair;
import java.util.*;

class Dfs {
    static int v, e;
    static HashMap<Integer, List<int[]>> graph = new HashMap<>();
//    static Stack<Integer> stack = new Stack<>();
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        v = scn.nextInt();
        e = scn.nextInt();

        for (int i = 0; i < e; i++) {
            int a = scn.nextInt();
            int b = scn.nextInt();
            int v = scn.nextInt();
            graph.putIfAbsent(a, new ArrayList<>());
            graph.putIfAbsent(b, new ArrayList<>());
            graph.get(a).add(new int[]{b, v});
            graph.get(b).add(new int[]{a, v});
        }
        System.out.println(dfs(scn.nextInt(), scn.nextInt(), 0, new ArrayList<>()));
    }

    public static int dfs(int current, int end, int steps, List<Integer> visited) {
        if (current == end) return steps;

        visited.add(current);
        List<int[]> neighbors = graph.get(current);
        Stack<int[]> stack = new Stack<>();

        for (int[] val : neighbors) {
            if (!stack.contains(val) && !visited.contains(val[0]))
                stack.add(val);
        }

        PriorityQueue<Integer> vals = new PriorityQueue<>();
        while (!stack.isEmpty()) {
            int[] next = stack.pop();
            vals.add(dfs(next[0], end, steps+next[1], visited));
        }
        if (!vals.isEmpty())
            return vals.poll();
        return 1000000000;
    }
}
