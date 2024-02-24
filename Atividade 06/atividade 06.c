#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

6- Lista duplamente encadeada circular e com elemento central

*/

// Estrutura do endereço
typedef struct {
    char rua[50];
    char cidade[50];
    char estado[3];
    char cep[10];
} Endereco;

// Estrutura do proprietário
typedef struct {
    char nome[50];
    int idade;
} Proprietario;

// Estrutura do produto
typedef struct {
    char nome[50];
    float preco;
} Produto;

// Estrutura da empresa
typedef struct Empresa {
    char nome[50];
    Endereco endereco;
    Proprietario proprietario;
    Produto produto;
    struct Empresa* prox;
    struct Empresa* ant;
} Empresa;

// Função auxiliar para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar uma nova empresa
Empresa* cadastrarEmpresa(Empresa* lista) {
    Empresa* novaEmpresa = (Empresa*)malloc(sizeof(Empresa));

    if (novaEmpresa == NULL) {
        printf("Erro ao alocar memória para a nova empresa\n");
        exit(1);
    }

    // Preencher os dados da empresa
    printf("Digite o nome da empresa: ");
    scanf("%s", novaEmpresa->nome);
    limparBuffer();  // Limpar o buffer para evitar problemas com o fgets

    printf("Digite a rua do endereço: ");
    fgets(novaEmpresa->endereco.rua, sizeof(novaEmpresa->endereco.rua), stdin);
    novaEmpresa->endereco.rua[strcspn(novaEmpresa->endereco.rua, "\n")] = '\0'; // Remover o caractere de nova linha

    // Preencher os demais dados do endereço (cidade, estado, cep) da mesma forma...

    // Preencher os dados do proprietário
    printf("Digite o nome do proprietário: ");
    fgets(novaEmpresa->proprietario.nome, sizeof(novaEmpresa->proprietario.nome), stdin);
    novaEmpresa->proprietario.nome[strcspn(novaEmpresa->proprietario.nome, "\n")] = '\0'; // Remover o caractere de nova linha

    printf("Digite a idade do proprietário: ");
    scanf("%d", &novaEmpresa->proprietario.idade);

    // Preencher os demais dados do proprietário da mesma forma...

    // Preencher os dados do produto
    printf("Digite o nome do produto: ");
    scanf("%s", novaEmpresa->produto.nome);
    limparBuffer();  // Limpar o buffer para evitar problemas com o fgets

    printf("Digite o preço do produto: ");
    scanf("%f", &novaEmpresa->produto.preco);

    novaEmpresa->prox = novaEmpresa->ant = NULL;

    // Adicionar a nova empresa à lista
    if (lista == NULL) {
        lista = novaEmpresa;
        lista->prox = lista->ant = lista; // A lista é circular, então ela aponta para si mesma
    } else {
        novaEmpresa->prox = lista;
        novaEmpresa->ant = lista->ant;
        lista->ant->prox = novaEmpresa;
        lista->ant = novaEmpresa;
    }

    return lista;
}

// Função para exibir as empresas cadastradas
void exibirEmpresas(Empresa* lista) {
    if (lista == NULL) {
        printf("Nenhuma empresa cadastrada\n");
        return;
    }

    Empresa* atual = lista;

    do {
        printf("\nNome da empresa: %s\n", atual->nome);
        printf("Endereço: %s, %s, %s, %s\n", atual->endereco.rua, atual->endereco.cidade, atual->endereco.estado, atual->endereco.cep);
        printf("Proprietário: %s (Idade: %d)\n", atual->proprietario.nome, atual->proprietario.idade);
        printf("Produto: %s (Preço: %.2f)\n", atual->produto.nome, atual->produto.preco);

        atual = atual->prox;
    } while (atual != lista);
}

// Função principal
int main() {
    Empresa* listaEmpresas = NULL;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar nova empresa\n");
        printf("2 - Exibir empresas cadastradas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listaEmpresas = cadastrarEmpresa(listaEmpresas);
                break;
            case 2:
                exibirEmpresas(listaEmpresas);
                break;
            case 0:
                // Liberar memória alocada para as empresas antes de sair
                break;
            default:
                printf("Opção inválida\n");
        }

    } while (opcao != 0);

    return 0;
}