#include "functions.h"



// Definir o número máximo de empresas
#define MAX_EMPRESAS 5


// Estrutura empresa
typedef struct
{
    char nome_empresa[256];
    char proprietario_empresa[256];
    char endereco_empresa[256];
    char cnpj_empresa[15]; // Usar uma string para CNPJ
    int quantidade_funcionarios_empresa;
} Empresa;

Empresa empresinhas[MAX_EMPRESAS];


// Estrutura endereço
typedef struct
{
    char pais[256], estado[256], municipio[256], logradouro[256];
    char numero[256], cep[8];
} Endereco; // fim da estrutura endereço

Empresa empresinhas[2];


// menu de opções
int main()
{
    CadastrarEmpresa();
    ExibeEmpresas();

    char busca[256];
    char campo[10];

    printf("\nInforme o campo para busca (nome ou cnpj): ");
    scanf("%9s", campo);
    getchar(); // Limpar o caractere de nova linha

    printf("Informe a busca: ");
    fgets(busca, sizeof(busca), stdin);

    BuscarEmpresa(busca, campo);

    return 0;
}
