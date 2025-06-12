import java.util.Scanner;

public class festa {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        int e = scan.nextInt();
        int s = scan.nextInt();
        int l = scan.nextInt();

        int dist = 0;
        if (s < e) {
            dist += e - s;
        } else {
            dist += s - e;
        }

        if (s < l) {
            dist += l - s;
        } else {
            dist += s - l;
        }
        dist += Math.abs(l - e);

        System.out.println(dist);
    }
}
