import java.util.*;

public class promocao {
    static class Path {
        int destine;
        boolean company;
        public Path(int destine, boolean company) {
            this.destine = destine;
            this.company = company;
        }
    }

    static Scanner scan = new Scanner(System.in);
    static int n;
    static Map<Integer, List<Path>> graph = new HashMap<>();

    static int defaultOrigin = -1;

    public static void main(String[] args) {
        n = scan.nextInt();
        for (int i = 0; i < n-1; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            boolean e = scan.nextInt() != 0;

            if (defaultOrigin == -1) defaultOrigin = a;

            graph.putIfAbsent(a, new ArrayList<>());
            graph.putIfAbsent(b, new ArrayList<>());
            graph.get(a).add(new Path(b, e));
            graph.get(b).add(new Path(a, e));
        }

        System.out.println(calc());
    }
    public static int calc() {
        boolean[] traversed = new boolean[n+1];
        traversed[defaultOrigin] = true;
        return traverseDFS(defaultOrigin, 1, traversed, null);
    }

    public static int traverseDFS(int node, int depth, boolean[] traversed, Boolean requiredCompany) {
        List<Path> paths = graph.get(node);
        int max = depth;


        for (Path p : paths) {
            Boolean nextCompany = requiredCompany == null ? !p.company : !requiredCompany;
            if (traversed[p.destine]) continue;
            if (requiredCompany != null && requiredCompany != p.company) {
                int distance = traverseDFS(p.destine, 1, traversed, null);
                if (distance > max) max = distance;
                continue;
            }

            System.out.printf("at: %d (%d) (comp. %b) going to: %d\n", node, depth, nextCompany, p.destine);

            traversed[node] = true;
            int distance = traverseDFS(p.destine, depth+1, traversed, nextCompany);
            traversed[node] = false;

            System.out.printf("left: %d with max: %d\n", p.destine, distance);

            if (distance > max) {
                max = distance;
            }
        }
        return max;
    }
}
