#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Estrutura empresa
typedef struct
{
    char nome_empresa[256], proprietario_empresa[256], endereco_empresa[256], cpnj_empresa[256];
    int quantidade_funcionarios_empresa[256];
} Empresa; // Fim da estrutura empresa

// Estrutura endere�o
typedef struct
{
    char pais[256], estado[256], municipio[256], logradouro[256];
    int numero[256], cep[8];
} Endereco; // fim da estrutura endere�o

Empresa empresinhas[2];

// procedimento para cadastrar 5 empresas
void CadastrarEmpresa()
{
    setlocale(LC_ALL, "Portuguese");
    int i;
    printf("\n\n Insira as informa��es da empresa!");
    for (i = 0; i < 2; i++)
    {
        printf("\n\n\n");
        printf("\n\ninforme o nome da sua empresa: ");
        fflush(stdin);
        fgets(empresinhas[i].nome_empresa, 255, stdin);

        printf("\n\ninforme o nome do proprietario da empresa: ");
        fflush(stdin);
        fgets(empresinhas[i].proprietario_empresa, 255, stdin);

        printf("\n\ninforme o endere�o da empresa: ");
        fflush(stdin);
        fgets(empresinhas[i].endereco_empresa, 255, stdin);

        printf("\n\ninforme o CNPJ da empresa: ");
        fflush(stdin);
        fgets(empresinhas[i].cpnj_empresa, 255, stdin);

        printf("\n\nInforme a quantidade de funcion�rios na empresa: ");
        fflush(stdin);
        scanf("%d%*c", empresinhas[i].quantidade_funcionarios_empresa);
    }
}

// Fun��o para exibir todas as empresas cadastradas
void ExibirEmpresasCadastradas()
{   
    int i;
	setlocale(LC_ALL, "Portuguese");
    printf("\n\nEmpresas Cadastradas:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("\nEmpresa %d:", i + 1);
        printf("\nNome: %s", empresinhas[i].nome_empresa);
        printf("Propriet�rio: %s", empresinhas[i].proprietario_empresa);
        printf("Endere�o: %s", empresinhas[i].endereco_empresa);
        printf("CNPJ: %s", empresinhas[i].cpnj_empresa);
        printf("Quantidade de funcion�rios: %d\n", empresinhas[i].quantidade_funcionarios_empresa);
    }
}
// Fun��o para buscar empresas por nome ou CNPJ

int main()
{   
    setlocale(LC_ALL, "Portuguese");
    CadastrarEmpresa();
    ExibirEmpresasCadastradas();
    
    system("Pause");
    return 0;
}
