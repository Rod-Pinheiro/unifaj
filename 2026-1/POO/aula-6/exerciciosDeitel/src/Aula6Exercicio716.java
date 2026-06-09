/*
 * Exercício 7.16 - Utilizando a Instrução for Aprimorada
 *
 * Escreva um aplicativo que utilize uma instrução for aprimorada (enhanced for)
 * para somar os valores double passados pelos argumentos da linha de comando.
 *
 * Dica: Utilize o método estático parseDouble da classe Double para converter
 * uma String em um valor double.
 */

public class Aula6Exercicio716 {
    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        if (args.length == 0) {
            System.out.println("Nenhum argumento fornecido.");
            System.out.println("Uso: java Aula6Exercicio716 <valor1> <valor2> ...");
            return;
        }

        double sum = 0.0;
        System.out.println("Valores fornecidos:");

        for (String arg : args) {
            double value = Double.parseDouble(arg);
            System.out.printf("  %.2f%n", value);
            sum += value;
        }

        System.out.printf("%nSoma total: %.2f%n", sum);
    }
}
