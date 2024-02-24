public class MultiplicacaoPorEscalar {

    public static void main(String[] args) {
        // Defina a matriz que você deseja multiplicar por um escalar
        int[][] matriz = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

        // Defina o escalar
        int escalar = 2;

        // Crie uma matriz para armazenar o resultado da multiplicação
        int[][] matrizMultiplicada = new int[matriz.length][matriz[0].length];

        // Realize a multiplicação da matriz pelo escalar
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[0].length; j++) {
                matrizMultiplicada[i][j] = matriz[i][j] * escalar;
            }
        }

        // Exiba a matriz resultante (multiplicação por escalar)
        System.out.println("Matriz Multiplicada por Escalar:");
        imprimirMatriz(matrizMultiplicada);
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
