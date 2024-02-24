#include <iostream>
#include <cstdlib>
#include <cstring>
/*

7- Finalizar arvore binaria (falta remover raiz)

*/
// Protótipo da função inserirNaArvore
struct Empresa;
Empresa* inserirNaArvore(Empresa* raiz, Empresa* novaEmpresa);

// Estrutura do endereço
struct Endereco {
    char rua[50];
    char cidade[50];
    char estado[3];
    char cep[10];
};

// Estrutura do proprietário
struct Proprietario {
    char nome[50];
    int idade;
};

// Estrutura do produto
struct Produto {
    char nome[50];
    float preco;
};

// Estrutura da empresa
struct Empresa {
    char nome[50];
    Endereco endereco;
    Proprietario proprietario;
    Produto produto;
    Empresa* esquerda;
    Empresa* direita;
};

// Função auxiliar para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Protótipo da função exibirEmpresas
void exibirEmpresas(Empresa* raiz);

// Função para cadastrar uma nova empresa
Empresa* cadastrarEmpresa(Empresa* raiz) {
    Empresa* novaEmpresa = new Empresa;

    // Preencher os dados da empresa
    std::cout << "Digite o nome da empresa: ";
    std::cin >> novaEmpresa->nome;
    limparBuffer();  // Limpar o buffer para evitar problemas com o fgets

    // Restante do preenchimento dos dados...

    novaEmpresa->esquerda = novaEmpresa->direita = nullptr;

    // Adicionar a nova empresa à árvore
    raiz = inserirNaArvore(raiz, novaEmpresa);

    return raiz;
}

// Função para inserir uma empresa na árvore binária de busca
Empresa* inserirNaArvore(Empresa* raiz, Empresa* novaEmpresa) {
    if (raiz == nullptr) {
        return novaEmpresa;
    }

    // Comparar o nome da nova empresa com o nome da empresa na raiz
    int comparacao = strcmp(novaEmpresa->nome, raiz->nome);

    // Inserir na subárvore esquerda se o nome for menor
    if (comparacao < 0) {
        raiz->esquerda = inserirNaArvore(raiz->esquerda, novaEmpresa);
    }
    // Inserir na subárvore direita se o nome for maior
    else if (comparacao > 0) {
        raiz->direita = inserirNaArvore(raiz->direita, novaEmpresa);
    }

    return raiz;
}

// Função para exibir as empresas em ordem na árvore binária
void exibirEmpresas(Empresa* raiz) {
    if (raiz != nullptr) {
        exibirEmpresas(raiz->esquerda);
        // Exibir os dados da empresa aqui
        exibirEmpresas(raiz->direita);
    }
}

// Função principal
int main() {
    Empresa* raizEmpresas = nullptr;
    int opcao;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1 - Cadastrar nova empresa\n";
        std::cout << "2 - Exibir empresas cadastradas\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                raizEmpresas = cadastrarEmpresa(raizEmpresas);
                break;
            case 2:
                exibirEmpresas(raizEmpresas);
                break;
            case 0:
                // Liberar memória alocada para as empresas antes de sair
                break;
            default:
                std::cout << "Opção inválida\n";
        }

    } while (opcao != 0);

    return 0;
}