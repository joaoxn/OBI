import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class zero {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        List<Integer> numbers = new ArrayList<>();
        int iterations = scan.nextInt();
        for (int i = 0; i < iterations; i++) {
            int in = scan.nextInt();
            if (in == 0) {
                if (numbers.isEmpty())
                    continue;
                numbers.remove(numbers.size()-1);
            } else {
                numbers.add(in);
            }
        }

        System.out.println(numbers.stream().reduce(Integer::sum).orElse(0));
    }
}
