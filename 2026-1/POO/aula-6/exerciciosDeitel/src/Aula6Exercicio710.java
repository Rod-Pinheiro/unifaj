/*
 * Exercício 7.10 - Comissões de Vendas
 *
 * Uma empresa paga seus vendedores por comissão. Os vendedores recebem
 * R$200/semana + 9% das vendas brutas. Este programa usa um array de contadores
 * para determinar quantos vendedores ganharam salários em cada faixa de R$100.
 */

import java.security.SecureRandom;

public class Aula6Exercicio710 {
    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        // Gera numeros aleatorios seguros
        SecureRandom random = new SecureRandom();
        // Array com 9 contadores para as faixas de R$200 ate R$1000+
        int[] counters = new int[9];
        // Array para armazenar as vendas dos 10 vendedores
        double[] sales = new double[10];

        System.out.println("Vendas brutas e salarios dos 10 vendedores:");
        System.out.println("-------------------------------------------------");
        // Processa cada um dos 10 vendedores
        for (int i = 0; i < 10; i++) {
            int salary = 200;
            // Gera valor aleatorio de vendas entre R$0 e R$10000
            sales[i] =  random.nextDouble() * 10000.0;
            // Calcula a comissao: 9% das vendas
            double comission = sales[i] * 0.09;
            System.out.printf("Vendedor %2d | Vendas: R$%7.2f | Comissao: R$%7.2f%n",
                    i + 1, sales[i], comission);

            // Determina a faixa salarial (divisao inteira por 100)
            int range = (int) (salary + comission) / 100;

            // Se salario >= R$1000, incrementa o ultimo contador
            if (range >= 10) {
                counters[8]++;
            // Senao, se salario >= R$200, incrementa o contador correspondente
            } else if (range >= 2) {
                counters[range - 2]++;
            }
        }

        // Exibe o resultado em formato de tabela
        System.out.println();
        System.out.println("Faixa salarial          | Quantidade");
        System.out.println("------------------------|-----------");
        for (int i = 0; i < counters.length; i++) {
            int lower = 200 + i * 100;
            int upper = lower + 99;
            if (i < 8) {
                System.out.printf("R$%d - R$%d           | %d%n", lower, upper, counters[i]);
            } else {
                System.out.printf("R$%d+                 | %d%n", lower, counters[i]);
            }
        }
    }
}
