import java.util.Arrays;

public class test {
    public static void main(String[] args) {
        int[] array = new int[]{1, 2, 3, 4, 5};
        int[] jogo = array.clone();

        jogo[1] = 10;

        System.out.println(Arrays.toString(array));
        System.out.println(Arrays.toString(jogo));
    }
}
