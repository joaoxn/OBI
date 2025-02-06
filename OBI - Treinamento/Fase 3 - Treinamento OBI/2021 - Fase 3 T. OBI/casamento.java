import java.util.Scanner;

public class casamento {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String n1 = scn.next();
        String n2 = scn.next();

        int size = (int) Math.max(n1.length(), n2.length());
        int i, j;
        i = j = -1;
        while ((i < size || j < size) && !n1.isEmpty() && !n2.isEmpty()) {
            i++; j++;
            char n1Alg = getAlgarism(n1, i);
            char n2Alg = getAlgarism(n2, j);
            if (n1Alg == n2Alg) continue;
            if (n1Alg > n2Alg) {
                n2 = removeAlgarism(n2, j);
                j--;
            } else {
                n1 = removeAlgarism(n1, i);
                i--;
            }
        }

        if (n1.isEmpty()) n1 = "-1";
        if (n2.isEmpty()) n2 = "-1";

        System.out.println(Integer.parseInt(n2) + " " + Integer.parseInt(n1));
    }

    private static char getAlgarism(String n, int i) {
        if (i >= n.length()) return '0';
        return n.charAt(n.length()-1-i);
    }

    private static String removeAlgarism(String n, int i) {
        StringBuilder numStr = new StringBuilder(n);
        int index = numStr.length()-1-i;
        if (index < 0) return n;
        numStr.deleteCharAt(index);
        return numStr.toString();
    }

}
