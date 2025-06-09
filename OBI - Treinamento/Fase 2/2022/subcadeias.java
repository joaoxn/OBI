import java.util.Scanner;

public class subcadeias {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        String chars = scan.next();

        int max = 0;
        for (int i = 0; i < chars.length(); i++) {
            for (int j = chars.length(); j > i; j--) {
                String sub = chars.substring(i, j);
                if (isPalindrome(sub)) {
                    max = Math.max(max, sub.length());
                    break;
                }
            }
        }
        System.out.println(max);
    }
    public static boolean isPalindrome(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length()-i-1))
                return false;
        }
        return true;
    }
}
