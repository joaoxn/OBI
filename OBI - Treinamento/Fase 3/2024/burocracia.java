/*
 * Exercício: https://neps.academy/br/exercise/2931
 * Iniciado: xx/xx/25 xx:xx
 * Resolvido em: NÃO RESOLVIDO (33/100)
 */

import java.util.*;

// 2s ~ 10^9
public class burocracia {
    static Scanner scan = new Scanner(System.in);
    static int MAX_N = (int) 1e5;
    @SuppressWarnings("all")
    static List<Integer>[] tree;
    static int[] p;

    public static void main(String[] args) {
        int n = scan.nextInt();

        tree = new ArrayList[n];
        p = new int[n+1];

        for (int i = 2; i <= n; i++) {
            p[i] = scan.nextInt();
            if (tree[p[i]] == null) tree[p[i]] = new ArrayList<>();
            tree[p[i]].add(i);
        }

        for (List<Integer> children : tree) {
            children.sort(Integer::compare);
        }

        int q = scan.nextInt();

        int[] v = new int[q];
        int[] k = new int[q];
        for (int i = 0; i < q; i++) {
            boolean relatorio = scan.nextInt() == 1;
            v[i] = scan.nextInt();
            if (relatorio)
                k[i] = scan.nextInt();
        }

        for (int i = 0; i < q; i++) {
            if (k[i] == 0) {
                resetDFS(v[i], v[i]);
                continue;
            }
            int nobre = v[i];
            for (int j = 1; j <= k[i]; j++) {
                List<Integer> paths = tree[nobre];
                nobre = paths.get(0);
            }

            System.out.println(nobre);
        }
    }

    public static void resetDFS(int nobre, int curr) {
        List<Integer> children = tree[curr];
        for (int i = 1; i < children.size(); i++) {
            int child = children.get(i);
            if (child < curr) System.out.println("Warn!");
            resetDFS(nobre, child);
            if (children.get(i) == child)
                i++;
        }
        if (children.size() < 1 
        || children.size() == 1 && children.get(0) != nobre) {
            int parent = children.get(0);
            int grandpa = tree[parent].get(0);
            grandpa
        }
    }

    // public static void _resetDFS(int nobre, int curr) {
    //     if (curr.children.isEmpty() && curr == node)
    //         return;
    //     for (int i = 0; i < curr.children.size();) {
    //         Node child = curr.children.get(i);
    //         resetDFS(node, child);
    //         if (curr.children.size() > 0 
    //         && child == curr.children.get(i)) 
    //             i++;
    //     }
    //     if (curr.children.isEmpty()
    //         && curr.parent != node) {
    //             curr.parent.parent.children.add(curr);
    //             curr.parent.children.remove(curr);
    //             curr.parent = curr.parent.parent;
    //     }
    // }

    static class Tree {
        Tree.Node head;

        static class Node {
            int id;
            Node parent;
            List<Node> children = new ArrayList<>();

            Node(int id, Node parent) {
                this.id = id;
                this.parent = parent;
            }

            Node(int id, Node parent, List<Node> children) {
                this(id, parent);
                this.children.addAll(children);
            }
        }

        Tree(Tree.Node head) {
            this.head = head;
        }

        Tree(int headId) {
            this(new Tree.Node(headId, null));
        }

        Tree(int headId, List<Tree.Node> headChildren) {
            this(new Tree.Node(headId, null, headChildren));
        }

        private Node dfs(int id, Tree.Node curr) {
            if (curr.id == id)
                return curr;
            if (curr.id > id)
                return null;

            for (Tree.Node child : curr.children) {
                Tree.Node node = dfs(id, child);
                if (node != null)
                    return node;
            }
            return null;
        }

        Tree.Node get(int id) {
            return dfs(id, head);
        }

        Tree.Node append(int id, Tree.Node parent) {
            Tree.Node node = new Tree.Node(id, parent);
            parent.children.add(node);
            return node;
        }

        Tree.Node append(int id, int parent) {
            return append(id, get(parent));
        }

        // bug: netos de node mantém seus filhos. Filhos dos netos não viram irmãos
        void resetDFS(Tree.Node node, Tree.Node curr) {
            if (curr.children.isEmpty() && curr == node)
                return;
            for (int i = 0; i < curr.children.size();) {
                Node child = curr.children.get(i);
                resetDFS(node, child);
                if (curr.children.size() > 0 
                && child == curr.children.get(i)) 
                    i++;
            }
            if (curr.children.isEmpty()
                && curr.parent != node) {
                    curr.parent.parent.children.add(curr);
                    curr.parent.children.remove(curr);
                    curr.parent = curr.parent.parent;
            }
        }

        void resetChildren(Tree.Node node) {
            resetDFS(node, node);
        }

        void resetChildren(int id) {
            resetChildren(get(id));
        }
    }
}