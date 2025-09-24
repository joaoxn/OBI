/*
 * Exercício: https://neps.academy/br/exercise/271
 * Iniciado: 13/09/25 20:14
 * Resolvido em: 13/09/2025 20:34 (9m)
 */

import java.util.*;

public class expressoes {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        String[] calls = new String[n];
        for (int i = 0; i < n; i++)
            calls[i] = scan.next();

        for (int i = 0; i < n; i++)
            System.out.println(solve(calls[i]));

        scan.close();
    }

    public static char solve(String str) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                stack.add(c);
                continue;
            }
            if (c == ')') c = '(';
            if (c == ']') c = '[';
            if (c == '}') c = '{';

            if (stack.isEmpty() || stack.pop() != c) return 'N';
        }

        return stack.isEmpty() ? 'S' : 'N';
    }
}
