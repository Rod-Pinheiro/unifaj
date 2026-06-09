/*
 * Exercício 7.11
 *
 * Escreva instruções que realizem as seguintes operações em um array
 * unidimensional:
 *
 * a) Configure os 10 elementos do array de inteiros counts com o valor zero.
 *
 * b) Adicione 1 a cada um dos 15 elementos do array de inteiros bonus.
 *
 * c) Exiba os cinco valores do array de inteiros bestScores em formato de
 *    coluna.
 */

import java.util.Arrays;

public class Aula6Exercicio711 {
    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        // a) Configure os 10 elementos do array de inteiros counts com o valor zero.
        int[] counts = new int[10];
        Arrays.fill(counts, 0);
        System.out.println("counts inicializado com zeros:");
        System.out.println(Arrays.toString(counts));
        System.out.println();

        // b) Adicione 1 a cada um dos 15 elementos do array de inteiros bonus.
        int[] bonus = new int[15];
        for (int i = 0; i < bonus.length; i++) {
            bonus[i] = i + 1;
        }
        for (int i = 0; i < bonus.length; i++) {
            bonus[i] += 1;
        }
        System.out.println("bonus apos adicionar 1 a cada elemento:");
        System.out.println(Arrays.toString(bonus));
        System.out.println();
        
        // c) Exiba os cinco valores do array de inteiros bestScores em formato de coluna.
        int[] bestScores = {78, 92, 85, 96, 88};
        System.out.println("bestScores em formato de coluna:");
        for (int i = 0; i < bestScores.length; i++) {
            System.out.printf("%d%n", bestScores[i]);
        }
    }
}
