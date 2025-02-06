import java.util.*;

public class barcos4 {
    static Queue<Vertex> pq = new PriorityQueue<>((v1, v2) -> v2.value - v1.value);
    static Map<Integer, List<Vertex>> graph = new HashMap<>();
    static int[][] results;
    static int[] parent;
    static List<Integer>[] pendingQueries;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt(), b = scan.nextInt();
        results = new int[n + 1][n + 1];
        parent = new int[n + 1];
        pendingQueries = new ArrayList[n + 1];

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            pendingQueries[i] = new ArrayList<>();
        }

        for (int k = 0; k < b; k++) {
            int i = scan.nextInt(), j = scan.nextInt(), p = scan.nextInt();
            pq.add(new Vertex(i, j, p));
        }

        int c = scan.nextInt();
        int[] c1 = new int[c];
        int[] c2 = new int[c];
        for (int i = 0; i < c; i++) {
            c1[i] = scan.nextInt();
            c2[i] = scan.nextInt();
            pendingQueries[c1[i]].add(i);
            pendingQueries[c2[i]].add(i);
        }

        processQueries(c, c1, c2);
        for (int i = 0; i < c; i++) {
            System.out.println(results[c1[i]][c2[i]]);
        }
    }

    private static void processQueries(int c, int[] c1, int[] c2) {
        while (!pq.isEmpty()) {
            Vertex edge = pq.poll();
            int rootA = find(edge.origin);
            int rootB = find(edge.destination);

            if (rootA != rootB) {
                if (pendingQueries[rootA].size() < pendingQueries[rootB].size()) {
                    int temp = rootA;
                    rootA = rootB;
                    rootB = temp;
                }

                union(rootA, rootB);
                for (int query : pendingQueries[rootB]) {
                    if (results[c1[query]][c2[query]] == 0) {
                        results[c1[query]][c2[query]] = edge.value;
                        results[c2[query]][c1[query]] = edge.value;
                    }
                }
                pendingQueries[rootA].addAll(pendingQueries[rootB]);
            }
        }
    }

    private static int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    private static void union(int a, int b) {
        parent[b] = a;
    }

    static class Vertex {
        int origin;
        int destination;
        int value;

        public Vertex(int origin, int destination, int value) {
            this.origin = origin;
            this.destination = destination;
            this.value = value;
        }
    }
}
