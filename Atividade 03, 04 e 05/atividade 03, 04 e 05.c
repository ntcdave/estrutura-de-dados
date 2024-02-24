#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
3- Lista encadeada da empresa. Com três estruturas: empresa, endereço, propietário e produto. A estrutura base é a empresa.

4- 3 com lista duplamente encadeada.

5- Aplicar busca sequencial e binária na 3 e na 4
*/

// Estrutura para representar o endereço
typedef struct Endereco {
  char rua[50];
  char cidade[30];
  char estado[30];
  int cep;
} Endereco;

// Estrutura para representar o proprietário
typedef struct Proprietario {
  char nome[50];
  int idade;
  Endereco endereco;
  char cnpj[15];
} Proprietario;

// Estrutura para representar o produto
typedef struct Produto {
  char nome[50];
  int id;
  float valor;
} Produto;

// Estrutura para representar a empresa
typedef struct Empresa {
  Endereco endereco;
  Proprietario proprietario;
  Produto produto;
  struct Empresa
      *proximaFilial; // Aponta para a próxima filial (ou NULL se não houver)
  struct Empresa *filialAnterior; // Aponta para a filial anterior (ou NULL se
                                  // for a primeira)
} Empresa;

// Função para adicionar uma nova filial à lista encadeada
void adicionarFilial(Empresa **listaEmpresas, Empresa novaFilial) {
  Empresa *novaEmpresa = (Empresa *)malloc(sizeof(Empresa));
  if (novaEmpresa == NULL) {
    printf("Erro ao alocar memória para a nova filial.\n");
    exit(1);
  }

  *novaEmpresa = novaFilial;
  novaEmpresa->proximaFilial = *listaEmpresas;
  novaEmpresa->filialAnterior = NULL;

  if (*listaEmpresas != NULL) {
    (*listaEmpresas)->filialAnterior = novaEmpresa;
  }

  *listaEmpresas = novaEmpresa;
}

// Função para imprimir os detalhes de uma empresa e suas filiais
void imprimirEmpresas(Empresa *listaEmpresas) {
  Empresa *atual = listaEmpresas;
  while (atual != NULL) {
    printf("Endereço: %s, %s, %s, CEP: %d\n", atual->endereco.rua,
           atual->endereco.cidade, atual->endereco.estado, atual->endereco.cep);
    printf("Proprietário: %s, Idade: %d, CNPJ: %s\n", atual->proprietario.nome,
           atual->proprietario.idade, atual->proprietario.cnpj);
    printf("Produto: %s, ID: %d, Valor: %.2f\n", atual->produto.nome,
           atual->produto.id, atual->produto.valor);
    printf("----------------------------\n");

    atual = atual->proximaFilial;
  }
}

// Função para limpar a tela do console
void limparTela() { system("cls"); }

// Função para perguntar se o usuário deseja continuar ou sair
int continuarOuSair() {
  int escolha;
  printf("Deseja adicionar outra filial? (1 para continuar, 0 para sair): ");
  scanf("%d", &escolha);

  return escolha;
}

// Função para realizar a busca sequencial por CNPJ
Empresa *buscaSequencial(Empresa *listaEmpresas, const char *cnpj) {
  Empresa *atual = listaEmpresas;
  while (atual != NULL) {
    if (strcmp(atual->proprietario.cnpj, cnpj) == 0) {
      return atual; // Retorna a empresa se encontrada
    }
    atual = atual->proximaFilial;
  }
  return NULL; // Retorna NULL se não encontrada
}

// Função para realizar a busca binária por CNPJ
Empresa *buscaBinaria(Empresa *listaEmpresas, const char *cnpj) {
  // Antes de usar busca binária, a lista deve estar ordenada pelo CNPJ
  // Aqui, usaremos uma busca sequencial para encontrar o início da lista
  // ordenada
  Empresa *atual = listaEmpresas;
  while (atual != NULL && atual->filialAnterior != NULL) {
    atual = atual->filialAnterior;
  }

  // Agora a lista está no início e podemos usar a busca binária
  while (atual != NULL) {
    int comparacao = strcmp(atual->proprietario.cnpj, cnpj);
    if (comparacao == 0) {
      return atual; // Retorna a empresa se encontrada
    } else if (comparacao < 0) {
      atual = atual->proximaFilial; // Move para a próxima filial
    } else {
      atual = atual->filialAnterior; // Move para a filial anterior
    }
  }

  return NULL; // Retorna NULL se não encontrada
}

// Função principal
int main() {
  int opcao = 1; // 1 para continuar, 0 para sair
  Empresa *listaEmpresas = NULL;

  while (opcao) {
    Empresa novaFilial;
    printf("Este programa cria um cadastro para empresa e seus produtos:\n");
    printf("Digite o endereço: \n");
    printf("Rua: ");
    scanf("%s", novaFilial.endereco.rua);

    printf("Cidade: ");
    scanf("%s", novaFilial.endereco.cidade);

    printf("Estado: ");
    getchar();
    fgets(novaFilial.endereco.estado, sizeof(novaFilial.endereco.estado),
          stdin);
    novaFilial.endereco.estado[strcspn(novaFilial.endereco.estado, "\n")] =
        '\0';

    printf("CEP: ");
    scanf("%d", &novaFilial.endereco.cep);

    printf("Digite o nome do proprietário: ");
    scanf("%s", novaFilial.proprietario.nome);

    printf("Digite a idade do proprietário: ");
    scanf("%d", &novaFilial.proprietario.idade);

    printf("Digite o CNPJ: ");
    scanf("%s", novaFilial.proprietario.cnpj);

    printf("CADASTRO PRODUTO:\n");
    printf("Digite o nome do produto: ");
    scanf("%s", novaFilial.produto.nome);

    printf("Digite o ID do produto: ");
    scanf("%d", &novaFilial.produto.id);

    printf("Digite o valor do produto: ");
    scanf("%f", &novaFilial.produto.valor);

    adicionarFilial(&listaEmpresas, novaFilial);

    limparTela();
    imprimirEmpresas(listaEmpresas);

    opcao = continuarOuSair();
  }

  // Imprimindo detalhes das empresas
  limparTela();
  imprimirEmpresas(listaEmpresas);

  // Escolhendo entre busca sequencial e busca binária
  int escolhaBusca;
  printf("Escolha o tipo de busca (1 para sequencial, 2 para binária, 0 para "
         "sair): ");
  scanf("%d", &escolhaBusca);

  if (escolhaBusca == 1 || escolhaBusca == 2) {
    char cnpjBusca[15];
    printf("Digite o CNPJ para buscar na lista: ");
    scanf("%s", cnpjBusca);

    Empresa *encontrada = (escolhaBusca == 1)
                              ? buscaSequencial(listaEmpresas, cnpjBusca)
                              : buscaBinaria(listaEmpresas, cnpjBusca);

    if (encontrada != NULL) {

      printf("Empresa encontrada:\n");
      printf("Endereço: %s, %s, %s, CEP: %d\n", encontrada->endereco.rua,
             encontrada->endereco.cidade, encontrada->endereco.estado,
             encontrada->endereco.cep);
      printf("Proprietário: %s, Idade: %d, CNPJ: %s\n",
             encontrada->proprietario.nome, encontrada->proprietario.idade,
             encontrada->proprietario.cnpj);
      printf("Produto: %s, ID: %d, Valor: %.2f\n", encontrada->produto.nome,
             encontrada->produto.id, encontrada->produto.valor);
      printf("----------------------------\n");
    } else {
      printf("Empresa não encontrada.\n");
    }
  }

  printf("Obrigado por utilizar nosso programa!\n");

  // Liberando a memória alocada
  while (listaEmpresas != NULL) {
    Empresa *temp = listaEmpresas;
    listaEmpresas = listaEmpresas->proximaFilial;
    free(temp);
  }

  return 0;
}