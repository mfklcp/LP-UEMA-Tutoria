#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define NUMERO 2

typedef struct
{
    float soma_salario_pais;
    float salario_mulher;
    int qtd_pai_solt;
    int posicao_da_mulher_mais_rica;
    int qtd_pai_adolescente_casado;
} Resultados;

Resultados processaDados(int *idade, int *sexo, int *estado_civil, int *filhos, float *salario);
void imprimeOResultado(Resultados result);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int idade[NUMERO], sexo[NUMERO], estado_civil[NUMERO], filhos[NUMERO];
    float salario[NUMERO];
    Resultados result;

    leiaOsFuncionarios(idade, sexo, estado_civil, filhos, salario);
    result = processaDados(idade, sexo, estado_civil, filhos, salario);
    imprimeOResultado(result);

    return 0;
}

void leiaOsFuncionarios(int *idade, int *sexo, int *estado_civil, int *filhos, float *salario)
{
    int retorno_idade, retorno_filhos;
    float retorno_salario, armazen_real;
    char armazen_letras;

    for(int i = 0; i<NUMERO; i++)
    {
        idade[i] = 0;
        sexo[i] = 0;
        estado_civil[i] = 0;
        filhos[i] = 0;
        salario[i] = 0;

        printf("\n\t\tFUNCIONÁRIO [ %i ] INFORME SEUS DADOS\n", i+1);

        do
        {
            printf("\nIDADE: ");
            retorno_idade = scanf("%i", &idade[i]);

            if(retorno_idade == 0)
            {
                printf("\n>> FORMATO INVÁLIDO. INFORME NOVAMENTE (EX: 26): \n");
                while (getchar() != '\n');
            }
        }
        while(idade[i] < 16 || idade[i] > 100);

        do
        {
            printf("\nSALÁRIO: ");
            retorno_salario = scanf("%f", &salario[i]);

            if(retorno_salario == 0)
            {
                printf("\n>> FORMATO INVÁLIDO. INFORME NOVAMENTE (EX: 2.000): \n");
                while (getchar() != '\n');
            }

        }
        while(salario[i] < 800);

        do
        {
            printf("\nQUANTIDADE DE FILHOS: ");
            retorno_filhos = scanf("%i", &filhos[i]);

            if(retorno_filhos == 0)
            {
                printf("\n>>FORMATO INVÁLIDO. INFORME NOVAMENTE (EX: 2): \n");
                while (getchar() != '\n');
            }
        }
        while(filhos[i] < 0);

        int retorno_sexo = 0;
        do
        {
            printf("\nSEXO: (1-MASCULINO) (2-FEMININO): ");
            retorno_sexo = scanf("%i", &sexo[i]);

            if(retorno_sexo == 0)
            {
                printf("\n>>FORMATO INVÁLIDO. ESCOLHA O NUMERO 1 OU O 2 : \n");
                while (getchar() != '\n');
            }
        }
        while(sexo[i] != 1 & sexo[i] != 2);

        int retorno_estado_civil = 0;
        do
        {
            printf("\nESTADO CIVIL (1-SOLTEIRO) (2-CASADO): ");
            retorno_estado_civil = scanf("%i", &estado_civil[i]);

            if(retorno_estado_civil == 0)
            {
                printf("\n>>FORMATO INVÁLIDO. ESCOLHA O NUMERO 1 OU O 2 : \n");
                while (getchar() != '\n');
            }
        }
        while(estado_civil[i] != 1 & estado_civil[i] != 2);
    }
}

void imprimeOResultado(Resultados result)
{

    if(result.qtd_pai_solt > 0)
    {
        printf("\nMÉDIA SALARIAL: FUNCIONÁRIOS PAIS IDOSOS SOLTEIROS: >> R$%.2f\n", result.soma_salario_pais / result.qtd_pai_solt);
    }
    else
    {
        printf("\nNENHUM REGISTRO PARA FUNCIONÁRIOS PAIS IDOSOS SOLTEIROS\n");
    }
    if(result.salario_mulher > 0)
    {
        printf("\nMAIOR SALÁRIO: FUNCIONÁRIAS SEM FILHO: >> R$%.2f DA FUNCIONÁRIA [ %i ]\n", result.salario_mulher,
               result.posicao_da_mulher_mais_rica);
    }
    else
    {
        printf("\nNENHUM REGISTRO PARA FUNCIONÁRIAS SOLTEIRAS SEM FILHOS\n");
    }
    if(result.qtd_pai_adolescente_casado > 0)
    {
        printf("\nQUANTIDADE DE FUNCIONÁRIOS: PAIS ADOLESCENTES, COM SALÁRIO ACIMA DE TRÊS MIL REAIS E CASADOS = >> %i\n", result.qtd_pai_adolescente_casado);
    }
    else if(result.qtd_pai_adolescente_casado < 1)
    {
        printf("\nNENHUM REGISTRO PARA PAIS ADOLESCENTES, COM SALÁRIO ACIMA DE TRÊS MIL REAIS E CASADOS. \n");
    }
}


Resultados processaDados(int *idade, int *sexo, int *estado_civil, int *filhos, float *salario)
{
    Resultados result;

    result.posicao_da_mulher_mais_rica = 0;
    result.qtd_pai_adolescente_casado = 0;
    result.qtd_pai_solt = 0;
    result.salario_mulher = 0;
    result.soma_salario_pais = 0;

    for(int i = 0; i<NUMERO; i++)
    {
        if(idade[i] >= 60 && sexo[i] == 1 && estado_civil[i] == 1 && filhos[i] > 0)
        {
            result.soma_salario_pais += salario[i];
            result.qtd_pai_solt++;
        }

        if(sexo[i] == 2 && filhos[i] == 0 && salario[i] > result.salario_mulher)
        {
            result.salario_mulher = salario[i];
            result.posicao_da_mulher_mais_rica = i;
        }

        if(idade[i] < 18 && filhos[i] > 0 && sexo[i] == 1 && estado_civil[i] == 2 && salario[i] > 3000)
        {
            result.qtd_pai_adolescente_casado++;
        }
    }

    return result;
}
