/*
 * Exercício 7.14 - Lista de Argumentos de Comprimento Variável
 *
 * Escreva um aplicativo que calcule o produto de uma série de inteiros
 * passados para o método product, utilizando uma lista de argumentos de
 * comprimento variável (varargs).
 *
 * Teste o método com várias chamadas, cada uma contendo uma quantidade
 * diferente de argumentos.
 */

public class Aula6Exercicio714 {

    public static int product(int... numbers) {
        int result = 1;
        for (int num : numbers) {
            result *= num;
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        System.out.printf("product(5) = %d%n", product(5));
        System.out.printf("product(3, 7) = %d%n", product(3, 7));
        System.out.printf("product(2, 4, 6) = %d%n", product(2, 4, 6));
        System.out.printf("product(1, 2, 3, 4, 5) = %d%n", product(1, 2, 3, 4, 5));
        System.out.printf("product(10, 20, 30) = %d%n", product(10, 20, 30));
    }
}
