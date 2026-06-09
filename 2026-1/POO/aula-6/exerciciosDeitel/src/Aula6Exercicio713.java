/*
 * Exercício 7.13
 *
 * Rotule os elementos do array bidimensional sales (3 × 5) para indicar a
 * ordem em que eles são configurados com zero pelo seguinte segmento de
 * programa:
 *
 * for (int row = 0; row < sales.length; row++)
 * {
 *     for (int col = 0; col < sales[row].length; col++)
 *     {
 *         sales[row][col] = 0;
 *     }
 * }
 */

public class Aula6Exercicio713 {

    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        int[][] sales = new int[3][5];
        int ordem = 0;

        System.out.println("Ordem de inicializacao dos elementos de sales[3][5]:\n");

        for (int row = 0; row < sales.length; row++) {
            for (int col = 0; col < sales[row].length; col++) {
                sales[row][col] = 0;
                ordem++;
                System.out.printf("sales[%d][%d] = 0  (ordem %d)%n", row, col, ordem);
            }
        }

        System.out.println("\nRepresentacao tabular da ordem:");
        System.out.println("        col 0   col 1   col 2   col 3   col 4");
        for (int row = 0; row < sales.length; row++) {
            System.out.printf("row %d: ", row);
            for (int col = 0; col < sales[row].length; col++) {
                int pos = row * sales[row].length + col + 1;
                System.out.printf("  [%2d]  ", pos);
            }
            System.out.println();
        }
    }
}
