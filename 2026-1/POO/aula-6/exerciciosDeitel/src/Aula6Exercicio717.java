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
