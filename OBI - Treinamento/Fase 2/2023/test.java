public class test {
    public static void main(String[] args) {

        System.out.println(squareDigits(9119));
    }
    static public int squareDigits(int n) {
        int result = 0;
        int digits = (int) Math.log10(n)+1;
        int pos = 0;
        for (int i = 0; i < digits; i++) {
            int digitSquared = (int) Math.pow((int) (n/Math.pow(10, i) % 10), 2);
            result += (int) (digitSquared * Math.pow(10, pos));
            if (digitSquared != 0)
                pos += (int) Math.log10(digitSquared);
            pos++;
        }
        return result;
    }
}
