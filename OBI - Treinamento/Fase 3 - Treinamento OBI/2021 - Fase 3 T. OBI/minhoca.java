import java.util.*;

public class minhoca {
    static HashMap<Integer, List<Integer>> tunnels = new HashMap<>();
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt();

        for (int i = 0; i < n - 1; i++) {
            int sala1 = scn.nextInt();
            int sala2 = scn.nextInt();
            tunnels.putIfAbsent(sala1, new ArrayList<>());
            tunnels.putIfAbsent(sala2, new ArrayList<>());
            tunnels.get(sala1).add(sala2);
            tunnels.get(sala2).add(sala1);
        }

        Map<Integer, List<Integer>> copy = new HashMap<>(tunnels);

        for (Map.Entry<Integer, List<Integer>> entry : copy.entrySet()) {
            entry.getValue();
        }
        System.out.println(tunnels);
    }
}
