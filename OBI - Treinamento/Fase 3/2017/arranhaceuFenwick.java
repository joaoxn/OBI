import java.util.*;

public class arranhaceuFenwick {
    static Scanner scan = new Scanner(System.in);
    static int[] fenwick;
    public static void main(String[] args) {
        int n = scan.nextInt();
        int q = scan.nextInt();
        int[] a = new int[n+1];
        for (int i = 1; i <= n; i++) {
            a[i] = scan.nextInt();
        }
        
        fenwick = new int[n+1];
        for (int idx = 1; idx <= n; idx++) {
            int rightmost = idx & (-idx);
            int j = idx - rightmost;
            fenwick[idx] = sumFenwick(j+1, idx-1) + a[idx];
        }

        List<Integer> sols = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int type = scan.nextInt();
            int floor = scan.nextInt();
            if (type == 1) {
                sols.add(sumFenwick(1, floor));
                continue;
            }
            updateFenwick(floor, scan.nextInt());
        }
        for (Integer sol : sols) {
            System.out.println(sol);
        }
    }

    public static void updateFenwick(int i, int v) {
        int diff = v - sumFenwick(i, i);
        int bits = i;
        while (bits < fenwick.length) {
            fenwick[bits] += diff;
            bits += (bits & -bits);
        }
    }

    public static int sumFenwick(int i, int j) {
        if (i > 1)
            return sumFenwick(1, j) - sumFenwick(1, i-1);

        int bits = j;
        int sum = 0;
        while (bits > 0) {
            sum += fenwick[bits];
            bits -= (bits & -bits);
        }

        return sum;
    }
}
