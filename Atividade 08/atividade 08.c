#include <iostream>
#include <cstdlib>
#include <cstring>
/*

8- Arvore ternaria de busca (pode utilizar a estrutura empresa)



*/
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
    Empresa* menor;
    Empresa* igual;
    Empresa* maior;
};

// Função auxiliar para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para inserir uma nova empresa na árvore ternária
Empresa* inserirNaArvore(Empresa* raiz, Empresa* novaEmpresa) {
    if (raiz == nullptr) {
        return novaEmpresa;
    }

    int comparacao = strcmp(novaEmpresa->nome, raiz->nome);

    if (comparacao < 0) {
        raiz->menor = inserirNaArvore(raiz->menor, novaEmpresa);
    } else if (comparacao == 0) {
        raiz->igual = inserirNaArvore(raiz->igual, novaEmpresa);
    } else {
        raiz->maior = inserirNaArvore(raiz->maior, novaEmpresa);
    }

    return raiz;
}

// Função para cadastrar uma nova empresa
Empresa* cadastrarEmpresa(Empresa* raiz) {
    Empresa* novaEmpresa = new Empresa;

    // Preencher os dados da empresa
    std::cout << "Digite o nome da empresa: ";
    std::cin >> novaEmpresa->nome;
    limparBuffer();  // Limpar o buffer para evitar problemas com o fgets

    // Restante do preenchimento dos dados...

    novaEmpresa->menor = novaEmpresa->igual = novaEmpresa->maior = nullptr;

    // Adicionar a nova empresa à árvore
    raiz = inserirNaArvore(raiz, novaEmpresa);

    return raiz;
}

// Função para exibir as empresas na árvore ternária
void exibirEmpresas(Empresa* raiz) {
    if (raiz != nullptr) {
        exibirEmpresas(raiz->menor);
        // Exibir os dados da empresa aqui
        std::cout << "Nome da empresa: " << raiz->nome << std::endl;
        exibirEmpresas(raiz->igual);
        exibirEmpresas(raiz->maior);
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