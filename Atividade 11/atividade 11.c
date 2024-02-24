#include <iostream>
#include <cstring>


/*

11- Arvore binaria de lista duplamente encadeada, com busca binaria na arvore e internamente em cada nó (pode utilizar a estrutura empresa)

*/


struct Endereco {
    char rua[50];
    char cidade[50];
    char estado[3];
    char cep[10];
};

struct Proprietario {
    char nome[50];
    int idade;
};

struct Produto {
    int id; // Adicionando um ID para identificar o produto
void obterDadosProduto(Produto& produto) {
    std::cout << "Digite os dados do produto:\n";
    std::cout << "ID: ";
    std::cin >> produto.id;
    limparBuffer();

    std::cout << "Nome: ";
    std::cin.getline(produto.nome, sizeof(produto.nome));

    std::cout << "Preço: ";
    std::cin >> produto.preco;
    limparBuffer();
}

Empresa* cadastrarEmpresa(Empresa* raiz) {
    Empresa* novaEmpresa = new Empresa;

    std::cout << "Digite o nome da empresa: ";
    std::cin.getline(novaEmpresa->nome, sizeof(novaEmpresa->nome));

    std::cout << "Digite o endereço da empresa:\n";
    std::cout << "Rua: ";
    std::cin.getline(novaEmpresa->endereco.rua, sizeof(novaEmpresa->endereco.rua));

    std::cout << "Cidade: ";
    std::cin.getline(novaEmpresa->endereco.cidade, sizeof(novaEmpresa->endereco.cidade));

    std::cout << "Estado: ";
    std::cin.getline(novaEmpresa->endereco.estado, sizeof(novaEmpresa->endereco.estado));

    std::cout << "CEP: ";
    std::cin.getline(novaEmpresa->endereco.cep, sizeof(novaEmpresa->endereco.cep));

    std::cout << "Digite os dados do proprietário:\n";
    std::cout << "Nome: ";
    std::cin.getline(novaEmpresa->proprietario.nome, sizeof(novaEmpresa->proprietario.nome));

    std::cout << "Idade: ";
    std::cin >> novaEmpresa->proprietario.idade;
    limparBuffer();

    obterDadosProduto(novaEmpresa->produto);

    novaEmpresa->esquerda = novaEmpresa->direita = nullptr;
    novaEmpresa->ant = novaEmpresa->prox = nullptr;

    raiz = inserirNaArvore(raiz, novaEmpresa);

    return raiz;
}

Empresa* buscarNaArvore(Empresa* raiz, const char* nome) {
    if (raiz == nullptr || strcmp(nome, raiz->nome) == 0) {
        return raiz;
    }

    if (strcmp(nome, raiz->nome) < 0) {
        return buscarNaArvore(raiz->esquerda, nome);
    } else {
        return buscarNaArvore(raiz->direita, nome);
    }
}

Produto* buscarProdutoPorNome(Empresa* raiz, const char* nomeProduto) {
    while (raiz != nullptr) {
        if (strcmp(nomeProduto, raiz->produto.nome) == 0) {
            return &raiz->produto;
        } else if (strcmp(nomeProduto, raiz->produto.nome) < 0) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }

    return nullptr;
}

Produto* buscarProdutoPorId(Empresa* raiz, int idProduto) {
    while (raiz != nullptr) {
        if (idProduto == raiz->produto.id) {
            return &raiz->produto;
        } else if (idProduto < raiz->produto.id) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }

    return nullptr;
}

void exibirEmpresas(Empresa* raiz) {
    if (raiz != nullptr) {
        exibirEmpresas(raiz->esquerda);
        std::cout << "Nome da empresa: " << raiz->nome << std::endl;
        exibirEmpresas(raiz->direita);
    }
}

//  função para liberar a memória alocada para as empresas.

int main() {
    Empresa* raizEmpresas = nullptr;
    int opcao;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1 - Cadastrar nova empresa\n";
        std::cout << "2 - Exibir empresas cadastradas\n";
        std::cout << "3 - Buscar empresa por nome\n";
        std::cout << "4 - Consultar produto por nome\n";
        std::cout << "5 - Consultar produto por ID\n";
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
            case 3: {
                char nomeBusca[50];
                std::cout << "Digite o nome da empresa para buscar: ";
                std::cin >> nomeBusca;

                Empresa* empresaEncontrada = buscarNaArvore(raizEmpresas, nomeBusca);
                if (empresaEncontrada != nullptr) {
                    std::cout << "Empresa encontrada: " << empresaEncontrada->nome << std::endl;
                } else {
                    std::cout << "Empresa não encontrada." << std::endl;
                }
                break;
            }
            case 4: {
                char nomeProduto[50];
                std::cout << "Digite o nome do produto para buscar: ";
                std::cin >> nomeProduto;

                Produto* produtoEncontrado = buscarProdutoPorNome(raizEmpresas, nomeProduto);
                if (produtoEncontrado != nullptr) {
                    std::cout << "Produto encontrado: " << produtoEncontrado->nome << std::endl;
                } else {
                    std::cout << "Produto não encontrado." << std::endl;
                }
                break;
            }
            case 5: {
                int idProduto;
                std::cout << "Digite o ID do produto para buscar: ";
                std::cin >> idProduto;

                Produto* produtoEncontrado = buscarProdutoPorId(raizEmpresas, idProduto);
                if (produtoEncontrado != nullptr) {
                    std::cout << "Produto encontrado: " << produtoEncontrado->nome << std::endl;
                } else {
                    std::cout << "Produto não encontrado." << std::endl;
                }
                break;
            }
            case 0:
                //liberação da memória alocada para as empresas antes de sair.
                break;
            default:
                std::cout << "Opção inválida\n";
        }

    } while (opcao != 0);

    return 0;
}