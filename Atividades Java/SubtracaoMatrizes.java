public class SubtracaoMatrizes {

    public static void main(String[] args) {
        // Defina as matrizes que você deseja subtrair
        int[][] matrizA = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int[][] matrizB = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

        // Verifique se as matrizes têm as mesmas dimensões
        if (matrizA.length != matrizB.length || matrizA[0].length != matrizB[0].length) {
            System.out.println("As matrizes têm dimensões diferentes. Não é possível realizar a subtração.");
            return;
        }

        // Crie uma matriz para armazenar a subtração
        int[][] matrizSubtracao = new int[matrizA.length][matrizA[0].length];

        // Realize a subtração das matrizes
        for (int i = 0; i < matrizA.length; i++) {
            for (int j = 0; j < matrizA[0].length; j++) {
                matrizSubtracao[i][j] = matrizA[i][j] - matrizB[i][j];
            }
        }

        // Exiba a matriz resultante (subtração)
        System.out.println("Matriz Subtração:");
        imprimirMatriz(matrizSubtracao);
    }

    // Método auxiliar para imprimir uma matriz
    private static void imprimirMatriz(int[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[0].length; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }
}
