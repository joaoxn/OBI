import java.util.*;

public class poligrama {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        scn.nextInt();

        String text = scn.next();

        System.out.println(isPoligram(text));
    }

    public static String isPoligram(String text) {
        int len = text.length();

        List<Integer> divisors = getDivisors(len);

        for (Integer divisor : divisors) {
            int divideAmt = len / divisor;
            List<String> substrings = new ArrayList<>();
            for (int j = 0; j < divideAmt; j += divisor + 1)
                substrings.add(text.substring(j, j + divisor));

            if (areAnagrams(substrings)) return substrings.getFirst();
        }
        return "*";
    }
    
    public static List<Integer> getDivisors(int n) {
        List<Integer> divisors = new ArrayList<>();
        for (int i = 1; i <= Math.sqrt(n); i++)
            if (n % i == 0) {
                divisors.add(i);
                if (i != n / i && n != n / i) divisors.add(n / i);
            }
        return divisors;
    }

    public static boolean areAnagrams(List<String> strings) {
        for (String string : strings)
            if (!Objects.equals(strings.getFirst(), string) && !areAnagrams(strings.getFirst(), string)) return false;
        return true;
    }
    public static boolean areAnagrams(String str1, String str2) {
        for (int i = 0; i < str2.length(); i++)
            if (str1.indexOf(str2.charAt(i)) == -1) return false;
        return true;
    }
}
