import java.util.Arrays;

public class Aula6Exercicio711 {
    public static void main(String[] args) {
        System.out.println("RA: 12530689");
        System.out.println("NOME: Rodolfo Rodrigues Pinheiro");
        System.out.println();

        int[] counts = new int[10];
        Arrays.fill(counts, 0);
        System.out.println("counts inicializado com zeros:");
        System.out.println(Arrays.toString(counts));
        System.out.println();

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

        int[] bestScores = {78, 92, 85, 96, 88};
        System.out.println("bestScores em formato de coluna:");
        for (int i = 0; i < bestScores.length; i++) {
            System.out.printf("%d%n", bestScores[i]);
        }
    }
}
