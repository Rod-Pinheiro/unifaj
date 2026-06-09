/*
 * Exercício 7.17 - Jogo de Dados
 *
 * Escreva um aplicativo para simular o lançamento de dois dados.
 *
 * O aplicativo deve utilizar um objeto da classe Random para lançar o primeiro
 * dado e novamente para lançar o segundo dado. Em seguida, deve calcular a soma
 * dos valores obtidos.
 *
 * Cada dado pode apresentar valores inteiros de 1 a 6, portanto a soma dos dois
 * dados pode variar de 2 a 12. A soma 7 é a mais frequente, enquanto as somas 2
 * e 12 são as menos frequentes.
 *
 * A Figura 7.28 apresenta as 36 combinações possíveis de dois dados.
 *
 * Seu aplicativo deve lançar os dados 36.000.000 de vezes. Utilize um array
 * unidimensional para contar o número de ocorrências de cada soma possível.
 *
 * Apresente os resultados em formato tabular.
 */

import java.security.SecureRandom;

public class Aula6Exercicio717 {
    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        SecureRandom random = new SecureRandom();
        int[] sums = new int[11];

        for (int roll = 0; roll < 36_000_000; roll++) {
            int die1 = 1 + random.nextInt(6);
            int die2 = 1 + random.nextInt(6);
            int sum = die1 + die2;
            sums[sum - 2]++;
        }

        System.out.println("Soma   Frequencia   Porcentagem");
        for (int i = 0; i < sums.length; i++) {
            int sumValue = i + 2;
            double percentage = (double) sums[i] / 36000000 * 100;
            System.out.printf("  %2d      %7d      %.2f%%%n", sumValue, sums[i], percentage);
        }
    }
}
