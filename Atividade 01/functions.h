#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


typedef struct Empresa Empresa;

// Função para cadastrar empresas
void CadastrarEmpresa()
{
    printf("\n\nInsira as informações da empresa:\n");

    for (int i = 0; i < MAX_EMPRESAS; i++)
    {
        printf("\nEmpresa %d:\n", i + 1);

        printf("Informe o nome da empresa: ");
        fgets(empresinhas[i].nome_empresa, sizeof(empresinhas[i].nome_empresa), stdin);

        printf("Informe o nome do proprietário: ");
        fgets(empresinhas[i].proprietario_empresa, sizeof(empresinhas[i].proprietario_empresa), stdin);

        printf("Informe o endereço da empresa: ");
        fgets(empresinhas[i].endereco_empresa, sizeof(empresinhas[i].endereco_empresa), stdin);

        printf("Informe o CNPJ da empresa: ");
        fgets(empresinhas[i].cnpj_empresa, sizeof(empresinhas[i].cnpj_empresa), stdin);

        printf("Informe a quantidade de funcionários na empresa: ");
        scanf("%d", &empresinhas[i].quantidade_funcionarios_empresa);
        getchar(); // Limpar o caractere de nova linha deixado pelo scanf
    }
}



// Função para exibir todas as empresas cadastradas
void ExibeEmpresas()
{
    printf("\n\nEmpresas Cadastradas:\n");

    for (int i = 0; i < MAX_EMPRESAS; i++)
    {
        printf("\nEmpresa %d:\n", i + 1);
        printf("Nome: %s", empresinhas[i].nome_empresa);
        printf("Proprietário: %s", empresinhas[i].proprietario_empresa);
        printf("Endereço: %s", empresinhas[i].endereco_empresa);
        printf("CNPJ: %s", empresinhas[i].cnpj_empresa);
        printf("Quantidade de funcionários: %d\n", empresinhas[i].quantidade_funcionarios_empresa);
    }
}



// Função para buscar empresas por nome ou CNPJ
void BuscarEmpresa(const char *busca, const char *campo)
{
    printf("\nResultados da busca por %s:\n", campo);

    int resultadosEncontrados = 0;

    for (int i = 0; i < MAX_EMPRESAS; i++)
    {
        if ((strcmp(campo, "nome") == 0 && strstr(empresinhas[i].nome_empresa, busca) != NULL) ||
            (strcmp(campo, "cnpj") == 0 && strstr(empresinhas[i].cnpj_empresa, busca) != NULL))
        {
            printf("\nEmpresa %d:\n", i + 1);
            printf("Nome: %s", empresinhas[i].nome_empresa);
            printf("Proprietário: %s", empresinhas[i].proprietario_empresa);
            printf("Endereço: %s", empresinhas[i].endereco_empresa);
            printf("CNPJ: %s", empresinhas[i].cnpj_empresa);
            printf("Quantidade de funcionários: %d\n", empresinhas[i].quantidade_funcionarios_empresa);
            resultadosEncontrados++;
        }
    }

    if (resultadosEncontrados == 0)
    {
        printf("Nenhum resultado encontrado para a busca por %s.\n", campo);
    }
}