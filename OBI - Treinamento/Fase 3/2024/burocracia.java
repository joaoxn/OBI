import java.util.*;

// 2s ~ 10^9
public class burocracia {
    static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scan.nextInt();

        Tree tree = new Tree(1);
        for (int i = 2; i <= n; i++) {
            tree.append(i, scan.nextInt());
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
                tree.resetChildren(v[i]);
                continue;
            }
            Tree.Node node = tree.get(v[i]);
            Tree.Node supervisor = node.parent;
            for (int j = 2; j <= k[i]; j++)
                supervisor = supervisor.parent;

            System.out.println(supervisor.id);
        }
    }

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
            for (int i = curr.children.size()-1; i >= 0; i--) {
                resetDFS(node, curr.children.get(i));
            }
            if (curr.children.isEmpty()
                    && curr.parent != node) {
                curr.parent = curr.parent.parent;
                curr.parent.children.add(curr);
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
