#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char pais[256], estado[256], municipio[256], logradouro[256];
    int numero;
    char cep[9];
} Endereco;

typedef struct {
    char cnpj_empresa[256], nome_empresa[256], proprietario_empresa[256];
    Endereco endereco;
    int quantidade_funcionarios_empresa;
} Empresa;

Empresa empresinhas[5];

void CadastrarEmpresa() {
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n Insira as informacoes da empresa!");
    for (int i = 0; i < 5; i++) {
        printf("\n\n\n");
        printf("\n\ninforme o nome da sua empresa: ");
        fgets(empresinhas[i].nome_empresa, sizeof(empresinhas[i].nome_empresa), stdin);
        empresinhas[i].nome_empresa[strcspn(empresinhas[i].nome_empresa, "\n")] = '\0'; // Remove a quebra de linha do fgets

        printf("\n\ninforme o nome do proprietario da empresa: ");
        fgets(empresinhas[i].proprietario_empresa, sizeof(empresinhas[i].proprietario_empresa), stdin);
        empresinhas[i].proprietario_empresa[strcspn(empresinhas[i].proprietario_empresa, "\n")] = '\0';

        printf("\n\ninforme o endereco da empresa: ");
        fgets(empresinhas[i].endereco.pais, sizeof(empresinhas[i].endereco.pais), stdin);
        empresinhas[i].endereco.pais[strcspn(empresinhas[i].endereco.pais, "\n")] = '\0';
        fgets(empresinhas[i].endereco.estado, sizeof(empresinhas[i].endereco.estado), stdin);
        empresinhas[i].endereco.estado[strcspn(empresinhas[i].endereco.estado, "\n")] = '\0';
        fgets(empresinhas[i].endereco.municipio, sizeof(empresinhas[i].endereco.municipio), stdin);
        empresinhas[i].endereco.municipio[strcspn(empresinhas[i].endereco.municipio, "\n")] = '\0';
        fgets(empresinhas[i].endereco.logradouro, sizeof(empresinhas[i].endereco.logradouro), stdin);
        empresinhas[i].endereco.logradouro[strcspn(empresinhas[i].endereco.logradouro, "\n")] = '\0';
        scanf("%d%*c", &empresinhas[i].endereco.numero);
        fgets(empresinhas[i].endereco.cep, sizeof(empresinhas[i].endereco.cep), stdin);
        empresinhas[i].endereco.cep[strcspn(empresinhas[i].endereco.cep, "\n")] = '\0';

        printf("\n\ninforme o CNPJ da empresa: ");
        fgets(empresinhas[i].cnpj_empresa, sizeof(empresinhas[i].cnpj_empresa), stdin);
        empresinhas[i].cnpj_empresa[strcspn(empresinhas[i].cnpj_empresa, "\n")] = '\0';

        printf("\n\nInforme a quantidade de funcionários na empresa: ");
        scanf("%d%*c", &empresinhas[i].quantidade_funcionarios_empresa);
    }
}

void ExibirEmpresa(Empresa empresa) {
    printf("\nNome: %s", empresa.nome_empresa);
    printf("\nProprietário: %s", empresa.proprietario_empresa);
    printf("\nEndereço: %s, %s, %s, %s, %d, %s", empresa.endereco.pais, empresa.endereco.estado, empresa.endereco.municipio, empresa.endereco.logradouro, empresa.endereco.numero, empresa.endereco.cep);
    printf("\nCNPJ: %s", empresa.cnpj_empresa);
    printf("\nQuantidade de funcionários: %d\n", empresa.quantidade_funcionarios_empresa);
}

void ExibirEmpresasCadastradas() {
    setlocale(LC_ALL, "Portuguese");
    printf("\n\nEmpresas Cadastradas:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEmpresa %d:", i + 1);
        ExibirEmpresa(empresinhas[i]);
    }
}

void BuscarEmpresa(const char *busca, const char *campo) {
    printf("\nResultados da busca por %s:\n", campo);
    int resultadosEncontrados = 0;
    for (int i = 0; i < 5; i++) {
        if ((strcmp(campo, "nome") == 0 && strstr(empresinhas[i].nome_empresa, busca) != NULL) ||
            (strcmp(campo, "cnpj") == 0 && strcmp(empresinhas[i].cnpj_empresa, busca) == 0)) {
            printf("\nEmpresa %d:", i + 1);
            ExibirEmpresa(empresinhas[i]);
            resultadosEncontrados++;
        }
    }

    if (resultadosEncontrados == 0) {
        printf("Nenhum resultado encontrado para a busca por %s.\n", campo);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    CadastrarEmpresa();
    ExibirEmpresasCadastradas();
    system("Pause");
    return 0;
}
