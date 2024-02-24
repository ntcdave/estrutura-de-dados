#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

10- Aplicar busca sequencial e binária na 9

*/
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(Fila *fila) {
    return (fila->inicio == NULL);
}

void enfileirar(Fila *fila, Pessoa pessoa) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    novoNo->pessoa = pessoa;
    novoNo->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

Pessoa desenfileirar(Fila *fila) {
    if (filaVazia(fila)) {
        fprintf(stderr, "Erro: Fila vazia.\n");
        exit(EXIT_FAILURE);
    }

    Pessoa pessoaDesenfileirada = fila->inicio->pessoa;

    No *temp = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);

    return pessoaDesenfileirada;
}

void imprimirFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Conteúdo da fila:\n");
    No *atual = fila->inicio;
    while (atual != NULL) {
        printf("Nome: %s, Idade: %d\n", atual->pessoa.nome, atual->pessoa.idade);
        atual = atual->prox;
    }
    printf("\n");
}

void ordenarFila(Fila *fila) {
    // Implementação de uma ordenação simples (Bubble Sort) para este exemplo.
    if (filaVazia(fila) || fila->inicio->prox == NULL) {
        // Fila vazia ou com apenas um elemento, já consideramos "ordenada".
        return;
    }

    int trocou;
    do {
        trocou = 0;
        No *atual = fila->inicio;
        No *anterior = NULL;

        while (atual->prox != NULL) {
            No *proximo = atual->prox;

            if (strcmp(atual->pessoa.nome, proximo->pessoa.nome) > 0) {
                // Troca os elementos
                if (anterior != NULL) {
                    anterior->prox = proximo;
                } else {
                    fila->inicio = proximo;
                }

                atual->prox = proximo->prox;
                proximo->prox = atual;
                trocou = 1;
            }

            anterior = atual;
            atual = atual->prox;
        }
    } while (trocou);
}

int buscarSequencial(Fila *fila, char nome[]) {
    No *atual = fila->inicio;
    int posicao = 1;

    while (atual != NULL) {
        if (strcmp(atual->pessoa.nome, nome) == 0) {
            printf("Pessoa %s encontrada na posição %d.\n", nome, posicao);
            return posicao;
        }

        atual = atual->prox;
        posicao++;
    }

    printf("Pessoa %s não encontrada na fila.\n", nome);
    return -1;
}

int buscarBinaria(Fila *fila, char nome[]) {
    ordenarFila(fila);

    No *inicio = fila->inicio;
    No *fim = fila->fim;

    int posicao = 1;
    while (inicio != NULL && fim != NULL && inicio != fim) {
        // Encontrar o ponto médio
        int tamanho = 0;
        No *temp = inicio;
        while (temp != fim) {
            temp = temp->prox;
            tamanho++;
        }
        int meioIndex = tamanho / 2;
        temp = inicio;
        for (int i = 0; i < meioIndex; i++) {
            temp = temp->prox;
        }
        No *meio = temp;

        // Comparar com o nome no ponto médio
        if (strcmp(meio->pessoa.nome, nome) == 0) {
            printf("Pessoa %s encontrada na posição %d.\n", nome, posicao);
            return posicao;
        } else if (strcmp(meio->pessoa.nome, nome) > 0) {
            // Se o nome no meio for maior, descartar a metade superior
            fim = meio;
        } else {
            // Se o nome no meio for menor, descartar a metade inferior
            inicio = meio->prox;
        }

        posicao++;
    }

    // Verificar o último elemento
    if (inicio != NULL && strcmp(inicio->pessoa.nome, nome) == 0) {
        printf("Pessoa %s encontrada na posição %d.\n", nome, posicao);
        return posicao;
    }

    printf("Pessoa %s não encontrada na fila.\n", nome);
    return -1;
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int removerPessoa(Fila *fila, char nome[]) {
    if (filaVazia(fila)) {
        printf("Fila vazia. Nenhuma pessoa para remover.\n");
        return 0;
    }

    No *anterior = NULL;
    No *atual = fila->inicio;

    while (atual != NULL) {
        if (strcmp(atual->pessoa.nome, nome) == 0) {
            if (anterior == NULL) {
                // Remover do início da fila
                fila->inicio = atual->prox;
                if (fila->inicio == NULL) {
                    fila->fim = NULL;
                }
            } else {
                // Remover do meio ou final da fila
                anterior->prox = atual->prox;
                if (anterior->prox == NULL) {
                    fila->fim = anterior;
                }
            }

            printf("Pessoa %s removida com sucesso!\n", nome);
            free(atual);
            return 1;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Pessoa %s não encontrada na fila.\n", nome);
    return 0;
}

int main() {
    Fila filaPessoas;
    inicializarFila(&filaPessoas);

    int opcao = 0;

    do {
        limparTela();
        printf("Escolha uma opção:\n");
        printf("1. Inserir Pessoa\n");
        printf("2. Remover Pessoa\n");
        printf("3. Imprimir Fila\n");
        printf("4. Buscar Sequencial\n");
        printf("5. Buscar Binária (após ordenar)\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Pessoa novaPessoa;
                printf("Digite o nome da pessoa: ");
                scanf("%s", novaPessoa.nome);
                printf("Digite a idade da pessoa: ");
                scanf("%d", &novaPessoa.idade);

                enfileirar(&filaPessoas, novaPessoa);
                printf("Pessoa adicionada com sucesso!\n");
                break;
            }
            case 2: {
                char nomeRemover[50];
                printf("Digite o nome da pessoa a ser removida: ");
                scanf("%s", nomeRemover);
                if (removerPessoa(&filaPessoas, nomeRemover)) {
                    // Pessoa removida com sucesso
                    printf("Pressione Enter para continuar...");
                    while (getchar() != '\n')
                        ;
                    getchar(); // Aguarda o usuário pressionar Enter
                }
                break;
            }
            case 3:
                limparTela();
                imprimirFila(&filaPessoas);
                printf("Pressione Enter para continuar...");
                while (getchar() != '\n')
                    ;
                getchar(); // Aguarda o usuário pressionar Enter
                break;
            case 4: {
                char nomeBuscar[50];
                printf("Digite o nome da pessoa a ser buscada (sequencial): ");
                scanf("%s", nomeBuscar);
                buscarSequencial(&filaPessoas, nomeBuscar);
                printf("Pressione Enter para continuar...");
                while (getchar() != '\n')
                    ;
                getchar(); // Aguarda o usuário pressionar Enter
                break;
            }
            case 5: {
                char nomeBuscar[50];
                printf("Ordenando a fila antes de buscar (busca binária)...\n");
                ordenarFila(&filaPessoas);
                printf("Digite o nome da pessoa a ser buscada (binária): ");
                scanf("%s", nomeBuscar);
                buscarBinaria(&filaPessoas, nomeBuscar);
                printf("Pressione Enter para continuar...");
                while (getchar() != '\n')
                    ;
                getchar(); // Aguarda o usuário pressionar Enter
                break;
            }
            case 0:
                limparTela();
                printf("OBRIGADA POR UTILIZAR NOSSO PROGRAMA!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}