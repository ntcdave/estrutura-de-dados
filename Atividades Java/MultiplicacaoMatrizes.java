public class MultiplicacaoMatrizes {

    public static void main(String[] args) {
        // Defina as matrizes que você deseja multiplicar
        int[][] matrizA = {{1, 2, 3}, {4, 5, 6}};
        int[][] matrizB = {{7, 8}, {9, 10}, {11, 12}};

        // Verifique se as matrizes podem ser multiplicadas
        if (matrizA[0].length != matrizB.length) {
            System.out.println("Número de colunas da matrizA não é igual ao número de linhas da matrizB. Não é possível multiplicar.");
            return;
        }

        // Crie uma matriz para armazenar o resultado da multiplicação
        int[][] matrizResultado = new int[matrizA.length][matrizB[0].length];

        // Realize a multiplicação das matrizes
        for (int i = 0; i < matrizA.length; i++) {
            for (int j = 0; j < matrizB[0].length; j++) {
                for (int k = 0; k < matrizA[0].length; k++) {
                    matrizResultado[i][j] += matrizA[i][k] * matrizB[k][j];
                }
            }
        }

        // Exiba a matriz resultante (multiplicação)
        System.out.println("Matriz Resultado da Multiplicação:");
        imprimirMatriz(matrizResultado);
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
