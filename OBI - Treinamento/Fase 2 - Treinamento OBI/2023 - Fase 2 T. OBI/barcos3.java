import java.util.*;

public class barcos3 {
    static Map<Integer, List<Vertex>> graph = new HashMap<>();
    static int[][] results;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt(), b = scan.nextInt();
        results = new int[n + 1][n + 1];

        for (int k = 0; k < b; k++) {
            int i = scan.nextInt(), j = scan.nextInt(), p = scan.nextInt();
            graph.putIfAbsent(i, new ArrayList<>());
            graph.putIfAbsent(j, new ArrayList<>());
            graph.get(i).add(new Vertex(j, p));
            graph.get(j).add(new Vertex(i, p));
        }

        int c = scan.nextInt();
        int[] c1 = new int[c];
        int[] c2 = new int[c];
        for (int i = 0; i < c; i++) {
            c1[i] = scan.nextInt();
            c2[i] = scan.nextInt();
        }

        for (int i = 0; i < c; i++) {
            int res = results[c1[i]][c2[i]] == 0 ? consulta(c1[i], c2[i]) : results[c1[i]][c2[i]];
            System.out.println(res);
        }
    }

    private static int consulta(int a, int b) {
        PriorityQueue<Vertex> pq = new PriorityQueue<>((v1, v2) -> v2.value - v1.value);
        pq.add(new Vertex(a, Integer.MAX_VALUE));
        boolean[] visited = new boolean[results.length];
        visited[a] = true;

        while (!pq.isEmpty()) {
            Vertex current = pq.poll();
            int node = current.destination;
            int pathValue = current.value;

            if (node == b) {
                results[a][b] = pathValue;
                return pathValue;
            }

            for (Vertex neighbor : graph.get(node)) {
                if (!visited[neighbor.destination]) {
                    visited[neighbor.destination] = true;
                    pq.add(new Vertex(neighbor.destination, Math.min(pathValue, neighbor.value)));
                }
            }
        }
        return -1; // Não deve acontecer se o grafo estiver conectado
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

        public Vertex(int destination, int value) {
            this.destination = destination;
            this.value = value;
        }
    }
}
