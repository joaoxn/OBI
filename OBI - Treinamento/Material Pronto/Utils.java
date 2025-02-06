package treinamentoObi.Joao;

import java.util.Arrays;
import java.util.Scanner;

public class Utils {
    public static class ScanUtil {
        public static String[] nextArray(Scanner scn) {
            return scn.nextLine().split("[,.\\s]");
        }

        public static int[] nextIntArray(Scanner scn) {
            return Arrays.stream(
                    scn.nextLine().split("[,.\\s]")
            ).mapToInt(Integer::parseInt).toArray();
        }

        public static double[] nextDoubleArray(Scanner scn) {
            return Arrays.stream(
                    scn.nextLine().split(" ")
            ).mapToDouble(Double::parseDouble).toArray();
        }

        public static String[][] nextMatrix(int rowsAmount, Scanner scn) {
            String[][] result = new String[rowsAmount][];
            for (int i = 0; i < rowsAmount; i++)
                result[i] = nextArray(scn);

            return result;
        }

        public static int[][] nextIntMatrix(int rowsAmount, Scanner scn) {
            int[][] result = new int[rowsAmount][];
            for (int i = 0; i < rowsAmount; i++)
                result[i] = nextIntArray(scn);

            return result;
        }

        public static double[][] nextDoubleMatrix(int rowsAmount, Scanner scn) {
            double[][] result = new double[rowsAmount][];
            for (int i = 0; i < rowsAmount; i++)
                result[i] = nextDoubleArray(scn);

            return result;
        }
    }

    public static class MatrixUtil {
        public static String[][] toString(int[][] matrix) {
            String[][] result = new String[matrix.length][];
            for (int i = 0; i < matrix.length; i++) {
                result[i] = new String[matrix[i].length];
                for (int j = 0; j < matrix[i].length; j++)
                    result[i][j] = Integer.toString(matrix[i][j]);
            }
            return result;
        }

        public static String[][] toString(double[][] matrix) {
            String[][] result = new String[matrix.length][];
            for (int i = 0; i < matrix.length; i++) {
                result[i] = new String[matrix[i].length];
                for (int j = 0; j < matrix[i].length; j++)
                    result[i][j] = Double.toString(matrix[i][j]);
            }
            return result;
        }

        public static String[][] toString(char[][] matrix) {
            String[][] result = new String[matrix.length][];
            for (int i = 0; i < matrix.length; i++) {
                result[i] = new String[matrix[i].length];
                for (int j = 0; j < matrix[i].length; j++)
                    result[i][j] = Character.toString(matrix[i][j]);
            }
            return result;
        }

        public static int[][] toInt(String[][] matrix) {
            int[][] result = new int[matrix.length][];
            for (int i = 0; i < matrix.length; i++) {
                result[i] = new int[matrix[i].length];
                for (int j = 0; j < matrix[i].length; j++)
                    result[i][j] = Integer.parseInt(matrix[i][j]);
            }
            return result;
        }

        public static int[][] toInt(double[][] matrix) {
            int[][] result = new int[matrix.length][];
            for (int i = 0; i < matrix.length; i++) {
                result[i] = new int[matrix[i].length];
                for (int j = 0; j < matrix[i].length; j++)
                    result[i][j] = (int) matrix[i][j];
            }
            return result;
        }

        public static double[][] toDouble(String[][] matrix) {
            double[][] result = new double[matrix.length][];
            for (int i = 0; i < matrix.length; i++) {
                result[i] = new double[matrix[i].length];
                for (int j = 0; j < matrix[i].length; j++)
                    result[i][j] = Double.parseDouble(matrix[i][j]);
            }
            return result;
        }

        public static char[][] toChar(String[][] matrix) {
            char[][] result = new char[matrix.length][];
            for (int i = 0; i < matrix.length; i++) {
                result[i] = new char[matrix[i].length];
                for (int j = 0; j < matrix[i].length; j++)
                    result[i][j] = matrix[i][j].charAt(0);
            }
            return result;
        }
    }
}
