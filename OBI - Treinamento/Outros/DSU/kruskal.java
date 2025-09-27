import java.util.*;

public class kruskal {
    static Scanner scan = new Scanner(System.in);
    static int[] id;
    static int[] sz;

    static class Aresta {
        int n1;
        int n2;
        int v;

        public Aresta(int n1, int n2, int v) {
            this.n1 = n1;
            this.n2 = n2;
            this.v = v;
        }

        @Override
        public String toString() {
            return "(%d, %d, %d)".formatted(this.n1, this.n2, this.v);
        }
    }

    public static void main(String[] args) {
        //             0  1  2  3  4  5
        id = new int[]{0, 1, 2, 3, 4, 5, 6};
        sz = new int[]{1, 1, 1, 1, 1, 1, 1};

        PriorityQueue<Aresta> pq = new PriorityQueue<>((a1, a2) -> a1.v-a2.v);
        pq.add(new Aresta(1,2,3));
        pq.add(new Aresta(2,5,5));
        pq.add(new Aresta(1,4,8));
        pq.add(new Aresta(4,2,2));
        pq.add(new Aresta(4,3,7));
        pq.add(new Aresta(2,3,4));
        pq.add(new Aresta(5,6,1));
        pq.add(new Aresta(3,6,1));

        List<Aresta> arestas = new ArrayList<>();

        while(!pq.isEmpty()) {
            Aresta a = pq.poll();
            if (find(a.n1) == find(a.n2)) continue;
            uni(a.n1, a.n2);
            arestas.add(a);
        }
        System.out.println(arestas);
    }

    static int find(int p) {
        return id[p] = (id[p] == p ? p : find(id[p]));
    }

    static void uni(int p, int q) {
        p = find(p);
        q = find(q);
        if (p == q) return;
        if (sz[p] > sz[q]) {
            int temp = p;
            p = q;
            q = temp;
        }

        id[p] = q;
        sz[q] += sz[p];
    }
}
