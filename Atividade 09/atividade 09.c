#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

9- Fila de estruturas do tipo pessoa

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