import java.util.*;

public class Inversions {
    public static void main(String[] args) {
        int[] array = new int[]{3, 1, 2, 3, 1, 0};
        int[] array2 = new int[]{3, 1, 2};
        int[] array3 = new int[]{3, 2, 1};
        System.out.println(brute(array));
        System.out.println(bit(array));
        
        System.out.println(brute(array2));
        System.out.println(bit(array2));

        System.out.println(brute(array3));
        System.out.println(bit(array3));
    }

    // * O(n^2)
    public static int brute(int[] array) {
        flipArray(array);

        int max = Integer.MIN_VALUE;
        for (int i = 0; i < array.length; i++) {
            if (array[i] > max) max = array[i];
        }

        int[] counts = new int[max+1];
        int sum = 0;
        for (int i = 0; i < array.length; i++) {
            counts[array[i]]++;
            for (int j = 0; j < array[i]; j++) {
                sum += counts[j];
                // System.out.println(array[i]+", "+j +" ("+counts[j]+"x)");
            }
        }
        flipArray(array);
        return sum;
    }

    // * O(nlogn)
    public static int bit(int[] array) {
        flipArray(array);
        int max = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] > max) max = array[i];
        }

        BinaryIndexedTree bit = new BinaryIndexedTree(max+2);
        int sum = 0;
        for (int i = 0; i < array.length; i++) {
            bit.add(array[i]+1, 1);
            sum += bit.sum(1, array[i]+1);
        }
        flipArray(array);
        return sum;
    }

    public static void flipArray(int[] array) {
        int l = 0;
        int r = array.length-1;
        while (l < r) {
            int temp = array[l];
            array[l] = array[r];
            array[r] = temp;
            l++;
            r--;
        }
    }
}

class BinaryIndexedTree {
    int[] prefix;

    public BinaryIndexedTree(int length) {
        prefix = new int[length];
    }

    int size() {
        return prefix.length;
    }
    int get(int i) {
        return sum(i, i+1);
    }
    
    // int i: included; int j: excluded
    int sum(int i, int j) {
        if (i >= j) return 0;
        if (i > 1) return sum(1, j) - sum(1, i);
        
        int bit = j-1;
        int sum = 0;
        while (bit > 0) {
            sum += prefix[bit];
            bit -= bit & -bit;
        }
        // if (i+1 == j) return sum;
        // System.out.printf("(%d, %d): %d\n", i, j, sum);
        return sum;
    }
    void add(int i, int v) {
        int bit = i;
        while (bit < prefix.length) {
            prefix[bit] += v;
            bit += bit&-bit;
        }
        // System.out.printf("(+) %d: %dx (%d)\n", i-1, sum(i, i+1), prefix[i]);
    }
}

/*
 * 0 (1x)
 * 
 */
