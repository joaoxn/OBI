import java.util.*;

public class concatenacoesSol
{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), q = in.nextInt();
		
		int[] lista = new int[n + 1];
		int[] prefixo = new int[n + 1];
		prefixo[0] = 0;
		for(int i = 1; i <= n; i++) {
		  lista[i] = in.nextInt();
		  prefixo[i] = lista[i] + prefixo[i - 1];
		}
		
		for(int i = 1; i <= q; i++) {
		  int l = in.nextInt(), r = in.nextInt();
		  long resp = 0;
		  long soma = prefixo[r] - prefixo[l - 1];
		  long tam = r - l;
		  resp += soma * 10 * tam;
		  resp += soma * (r - l + 1);
		  resp -= soma;
		  System.out.println(resp);
		}
	}
}