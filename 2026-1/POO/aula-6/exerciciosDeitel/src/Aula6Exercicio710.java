import java.security.SecureRandom;

public class Aula6Exercicio710 {
    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        int[] counters = new int[10];
        SecureRandom random = new SecureRandom();

        for (int i = 0; i < 100; i++) {
            double grossSales = 1000 + random.nextDouble() * 9000;
            int salary = (int) (200 + 0.09 * grossSales);

            int index = (salary - 200) / 100;
            if (index >= 10) {
                index = 9;
            }

            counters[index]++;
        }

        System.out.println("Faixa Salarial        Quantidade");
        for (int i = 0; i < counters.length - 1; i++) {
            int lower = 200 + i * 100;
            int upper = lower + 99;
            System.out.printf("$%d-%d             %3d%n", lower, upper, counters[i]);
        }
        System.out.printf("$1000 em diante       %3d%n", counters[9]);
    }
}
