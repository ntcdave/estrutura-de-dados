#include <stdio.h>
#include <stdlib.h> // Para a função system
/*

1- Ordenação (método bolha em matrizes : ordenando cada linha e depois ordenando a matriz inteira). Ordenação crescente e decrescente. Com e sem rebatimento para vetor.

2- Aplicar busca sequencial e binária na 1.

*/
// Função para ordenar um vetor usando o método bolha
void bubbleSort(int array[], int n, int ordenacao) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ordenacao && array[j] > array[j + 1]) || (!ordenacao && array[j] < array[j + 1])) {
                // Troca os elementos se estiverem fora de ordem
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Função para imprimir a matriz
void printMatriz(int matriz[][100], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para busca sequencial em um vetor ordenado
int buscaSequencial(int array[], int n, int elemento) {
    for (int i = 0; i < n; i++) {
        if (array[i] == elemento) {
            return i; // Retorna o índice do elemento se encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função para busca binária em um vetor ordenado
int buscaBinaria(int array[], int n, int elemento) {
    int esquerda = 0;
    int direita = n - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (array[meio] == elemento) {
            return meio; // Retorna o índice do elemento se encontrado
        }
        if (array[meio] < elemento) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

int main() {
    int continueProgram = 1; // continuamos no programa

    while (continueProgram) {
        int linhas, colunas;
        printf("Digite o número de linhas e colunas da matriz: ");
        scanf("%d %d", &linhas, &colunas);

        int matriz[100][100];

        printf("Digite os elementos da matriz:\n");
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        int ordenacao;
        printf("Digite 1 para ordenação crescente ou 0 para ordenação decrescente: ");
        scanf("%d", &ordenacao);

        // Verifique se o usuário inseriu uma opção válida
        if (ordenacao != 0 && ordenacao != 1) {
            printf("Opção inválida. Use 1 para ordenação crescente ou 0 para ordenação decrescente.\n");
            continue; // Continue o loop sem sair do programa
        }

        // Transforma a matriz em um vetor unidimensional
        int vetor[10000]; // Tamanho máximo da matriz
        int index = 0;
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                vetor[index] = matriz[i][j];
                index++;
            }
        }

        // Ordena o vetor em ordem crescente ou decrescente
        bubbleSort(vetor, linhas * colunas, ordenacao);

        // Recria a matriz a partir do vetor ordenado
        index = 0;
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                matriz[i][j] = vetor[index];
                index++;
            }
        }

        printf("Matriz ordenada:\n");
        printMatriz(matriz, linhas, colunas);

        int tipoBusca;
        printf("Digite 1 para busca sequencial ou 0 para busca binária: ");
        scanf("%d", &tipoBusca);

        int elemento;
        printf("Digite o elemento a ser buscado: ");
        scanf("%d", &elemento);

        int resultado;
        if (tipoBusca == 1) {
            resultado = buscaSequencial(vetor, linhas * colunas, elemento);
        } else if (tipoBusca == 0) {
            resultado = buscaBinaria(vetor, linhas * colunas, elemento);
        } else {
            printf("Opção de busca inválida.\n");
            continue; // Continue o loop sem sair do programa
        }

        if (resultado != -1) {
            printf("Elemento encontrado na posição %d.\n", resultado);
        } else {
            printf("Elemento não encontrado.\n");
        }

        int opcao;
        printf("Digite 1 para continuar no programa ou 0 para sair: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            system("clear");
            printf("OBRIGADO POR UTILIZAR NOSSO PROGRAMA\n");
            continueProgram = 0; // Sai do programa
        }
    }

    return 0;
}