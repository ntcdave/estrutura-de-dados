public class MultiplicacaoStrassen {

    public static void main(String[] args) {
        // Defina as matrizes que você deseja multiplicar
        int[][] matrizA = {{1, 2}, {3, 4}};
        int[][] matrizB = {{5, 6}, {7, 8}};

        // Verifique se as matrizes têm as mesmas dimensões
        if (matrizA.length != matrizA[0].length || matrizB.length != matrizB[0].length || matrizA.length != matrizB.length) {
            System.out.println("As matrizes devem ser quadradas e do mesmo tamanho para usar o algoritmo de Strassen.");
            return;
        }

        // Realiza a multiplicação usando o algoritmo de Strassen
        int[][] matrizResultado = multiplicacaoStrassen(matrizA, matrizB);

        // Exibe a matriz resultante
        System.out.println("Matriz Resultado da Multiplicação:");
        imprimirMatriz(matrizResultado);
    }

    private static int[][] multiplicacaoStrassen(int[][] A, int[][] B) {
        int n = A.length;

        // Caso base para a multiplicação trivial
        if (n <= 2) {
            return multiplicacaoTrivial(A, B);
        }

        // Divide as matrizes em quatro submatrizes
        int[][] A11 = divideMatriz(A, 0, 0);
        int[][] A12 = divideMatriz(A, 0, n / 2);
        int[][] A21 = divideMatriz(A, n / 2, 0);
        int[][] A22 = divideMatriz(A, n / 2, n / 2);

        int[][] B11 = divideMatriz(B, 0, 0);
        int[][] B12 = divideMatriz(B, 0, n / 2);
        int[][] B21 = divideMatriz(B, n / 2, 0);
        int[][] B22 = divideMatriz(B, n / 2, n / 2);

        // Calcula sete produtos P1 a P7 recursivamente
        int[][] P1 = multiplicacaoStrassen(somarMatrizes(A11, A22), somarMatrizes(B11, B22));
        int[][] P2 = multiplicacaoStrassen(somarMatrizes(A21, A22), B11);
        int[][] P3 = multiplicacaoStrassen(A11, subtrairMatrizes(B12, B22));
        int[][] P4 = multiplicacaoStrassen(A22, subtrairMatrizes(B21, B11));
        int[][] P5 = multiplicacaoStrassen(somarMatrizes(A11, A12), B22);
        int[][] P6 = multiplicacaoStrassen(subtrairMatrizes(A21, A11), somarMatrizes(B11, B12));
        int[][] P7 = multiplicacaoStrassen(subtrairMatrizes(A12, A22), somarMatrizes(B21, B22));

        // Calcula as submatrizes do resultado
        int[][] C11 = subtrairMatrizes(somarMatrizes(somarMatrizes(P1, P4), P7), P5);
        int[][] C12 = somarMatrizes(P3, P5);
        int[][] C21 = somarMatrizes(P2, P4);
        int[][] C22 = subtrairMatrizes(somarMatrizes(somarMatrizes(P1, P3), P6), P2);

        // Combina as submatrizes para obter o resultado final
        int[][] resultado = new int[n][n];
        unirMatriz(resultado, C11, 0, 0);
        unirMatriz(resultado, C12, 0, n / 2);
        unirMatriz(resultado, C21, n / 2, 0);
        unirMatriz(resultado, C22, n / 2, n / 2);

        return resultado;
    }

    private static int[][] multiplicacaoTrivial(int[][] A, int[][] B) {
        int n = A.length;
        int[][] resultado = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    resultado[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return resultado;
    }

    private static int[][] divideMatriz(int[][] matriz, int inicioLinha, int inicioColuna) {
        int n = matriz.length / 2;
        int[][] resultado = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                resultado[i][j] = matriz[inicioLinha + i][inicioColuna + j];
            }
        }

        return resultado;
    }

    private static void unirMatriz(int[][] matriz, int[][] submatriz, int inicioLinha, int inicioColuna) {
        int n = submatriz.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matriz[inicioLinha + i][inicioColuna + j] = submatriz[i][j];
            }
        }
    }

    private static int[][] somarMatrizes(int[][] A, int[][] B) {
        int n = A.length;
        int[][] resultado = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                resultado[i][j] = A[i][j] + B[i][j];
            }
        }

        return resultado;
    }

    private static int[][] subtrairMatrizes(int[][] A, int[][] B) {
        int n = A.length;
        int[][] resultado = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                resultado[i][j] = A[i][j] - B[i][j];
            }
        }

        return resultado;
    }

    private static void imprimirMatriz(int[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[0].length; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }
}
