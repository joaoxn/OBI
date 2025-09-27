import java.util.*;

public class dsu {
    static Scanner scan = new Scanner(System.in);
    static int[] id;
    static int[] sz;

    public static void main(String[] args) {
        //             0  1  2  3  4  5
        id = new int[]{0, 1, 2, 3, 4, 5};
        sz = new int[]{1, 1, 1, 1, 1, 1};

        System.out.println(find(4));
        System.out.println(find(3));
        uni(2, 1);
        uni(3, 1);
        uni(0, 1);
        uni(5, 4);
        System.out.println(find(3));
        System.out.println(find(5));
        uni(5, 3);
        System.out.println(find(4));
        // 4 3 1 4 1
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
