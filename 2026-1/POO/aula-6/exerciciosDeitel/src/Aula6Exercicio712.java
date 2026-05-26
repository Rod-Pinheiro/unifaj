import java.util.Scanner;

public class Aula6Exercicio712 {
    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        Scanner input = new Scanner(System.in);
        int[] uniqueValues = new int[5];
        int count = 0;

        while (count < 5) {
            System.out.printf("Insira o numero %d (10-100): ", count + 1);
            int num = input.nextInt();

            if (num < 10 || num > 100) {
                System.out.println("Numero invalido. Digite um numero entre 10 e 100.");
                continue;
            }

            boolean isDuplicate = false;
            for (int i = 0; i < count; i++) {
                if (uniqueValues[i] == num) {
                    isDuplicate = true;
                    break;
                }
            }

            if (!isDuplicate) {
                uniqueValues[count] = num;
                count++;
            } else {
                System.out.println("Numero duplicado. Tente novamente.");
            }

            System.out.print("Valores unicos ate agora: ");
            for (int i = 0; i < count; i++) {
                System.out.print(uniqueValues[i] + " ");
            }
            System.out.println();
            System.out.println();
        }

        System.out.print("Conjunto completo de valores unicos: ");
        for (int i = 0; i < uniqueValues.length; i++) {
            System.out.print(uniqueValues[i] + " ");
        }
        System.out.println();

        input.close();
    }
}
