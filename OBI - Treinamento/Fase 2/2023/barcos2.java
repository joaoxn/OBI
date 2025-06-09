import java.util.*;

public class barcos2 {
    static Map<Integer, List<Vertex>> graph = new HashMap<>();
    static int[][] results;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt(), b = scan.nextInt();
        results = new int[n+1][n+1];

        for (int k = 0; k < b; k++) {
            int i = scan.nextInt(), j = scan.nextInt(), p = scan.nextInt();
            graph.putIfAbsent(i, new ArrayList<>());
            graph.putIfAbsent(j, new ArrayList<>());
            graph.get(i).add(new Vertex(i, j, p));
            graph.get(j).add(new Vertex(j, i, p));
        }

        int c = scan.nextInt();
        int[] c1 = new int[c];
        int [] c2 = new int[c];
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
        Queue<Vertex> queue = new ArrayDeque<>();
        Set<Integer> completed = new HashSet<>();

        List<Vertex> paths = graph.get(a);
        paths.sort((o1, o2) -> o2.value - o1.value);
        queue.addAll(paths);
        completed.add(a);
        results[a][a] = 100001;

        while (!queue.isEmpty()) {
            Vertex vertex = queue.remove();
            completed.add(vertex.origin);

            int nodeValue = Math.min(vertex.value, results[a][vertex.origin]);

            results[a][vertex.destination] = results[a][vertex.destination] == 0 ?
                    nodeValue : Math.max(results[a][vertex.destination], nodeValue);

            List<Vertex> nextVertexes = graph.get(vertex.destination);

            for (Vertex nextVertex : nextVertexes)
                if (!completed.contains(nextVertex.destination))
                    queue.add(nextVertex);
        }
        return results[a][b];
    }
}

class Vertex {
    int origin;
    int destination;
    int value;

    public Vertex(int origin, int destination, int value) {
        this.origin = origin;
        this.destination = destination;
        this.value = value;
    }
}
