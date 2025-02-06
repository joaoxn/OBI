import java.util.*;

public class barcos5 {
    static Scanner scanner = new Scanner(System.in);
    static int[] parent, depth, answer;
    static List<Set<Integer>> queriesInNode;
    static List<List<Integer>> queries, edges;
    static int c;

    public static void main(String[] args) {
        List<Integer> firstInput = readIntList();
        int n = firstInput.get(0);
        int b = firstInput.get(1);
        edges = new ArrayList<>();
        for (int i = 0; i < b; i++) {
            edges.add(readIntList());
        }
        c = readInt();
        queries = new ArrayList<>();
        for (int i = 0; i < c; i++) {
            queries.add(readIntList());
        }

        // union-find init
        parent = new int[n + 1];
        depth = new int[n + 1];
        queriesInNode = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            queriesInNode.add(new HashSet<>());
        }
        answer = new int[c];
        Arrays.fill(answer, -1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        solve();
        for (int i = 0; i < c; i++) {
            System.out.println(answer[i]);
        }
    }

    static int readInt() {
        return Integer.parseInt(scanner.nextLine());
    }

    static List<Integer> readIntList() {
        return Arrays.stream(
                scanner.nextLine().split("[,.\\s]")
        ).map(Integer::valueOf).toList();
    }

    public static int dsuFind(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = dsuFind(parent[x]); // path compression
        return parent[x];
    }

    public static void dsuMerge(int v, int w, int cap) {
        v = dsuFind(v);
        w = dsuFind(w);
        if (v == w) {
            return;
        }

        // union by rank
        if (depth[v] < depth[w]) {
            int temp = v;
            v = w;
            w = temp;
        }
        parent[w] = v;
        if (depth[v] == depth[w]) {
            depth[v]++;
        }

        // small-to-large sets merge
        boolean swapped = false;
        if (queriesInNode.get(v).size() < queriesInNode.get(w).size()) {
            int temp = v;
            v = w;
            w = temp;
            swapped = true;
        }

        for (int qId : queriesInNode.get(w)) {
            if (queriesInNode.get(v).contains(qId)) {
                // acabei de encontrar a resposta pra consulta com indice qId
                queriesInNode.get(v).remove(qId);
                answer[qId] = cap;
            } else {
                // ainda nao encontrei o outro vertice da consulta qId
                queriesInNode.get(v).add(qId);
            }
        }
        queriesInNode.get(w).clear();

        if (swapped) {
            Set<Integer> tempSet = queriesInNode.get(v);
            queriesInNode.set(v, queriesInNode.get(w));
            queriesInNode.set(w, tempSet);
        }
    }

    public static void solve() {
        // coloca as consultas nos sets corretos
        for (int i = 0; i < c; i++) {
            List<Integer> query = queries.get(i);
            int x = query.get(0);
            int y = query.get(1);
            queriesInNode.get(x).add(i);
            queriesInNode.get(y).add(i);
        }

        // processa arestas ordenadas de maior pra menor capacidade
        edges.sort((a, b) -> Integer.compare(b.get(2), a.get(2)));
        for (List<Integer> edge : edges) {
            int v = edge.get(0);
            int w = edge.get(1);
            int cap = edge.get(2);
            dsuMerge(v, w, cap);
        }
    }
}
