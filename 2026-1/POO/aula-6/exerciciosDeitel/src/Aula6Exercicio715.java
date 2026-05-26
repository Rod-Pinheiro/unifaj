import java.security.SecureRandom;

public class Aula6Exercicio715 {
    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        int arraySize = 10;

        if (args.length > 0) {
            try {
                arraySize = Integer.parseInt(args[0]);
            } catch (NumberFormatException e) {
                System.out.println("Argumento invalido. Usando tamanho padrao 10.");
            }
        }

        int[] array = new int[arraySize];
        SecureRandom random = new SecureRandom();

        System.out.printf("Criando array de tamanho %d:%n", arraySize);
        System.out.print("Valores: ");

        for (int i = 0; i < array.length; i++) {
            array[i] = random.nextInt(100);
            System.out.print(array[i] + " ");
        }
        System.out.println();

        int sum = 0;
        for (int value : array) {
            sum += value;
        }
        double average = (double) sum / array.length;

        System.out.printf("Soma: %d%n", sum);
        System.out.printf("Media: %.2f%n", average);
    }
}
