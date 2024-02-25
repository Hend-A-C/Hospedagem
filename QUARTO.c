#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "QUARTO.h"
#include "APRESENTACAO.h"

const char SeparadorCSV = ';';
const char ArquivoQuartoCSV [] = "Quarto.csv";
const char ArquivoQuartoDat [] = "Quarto.dat";

//função para ler dados dos  quartos
void lerQuarto (QUARTO *p)
{
    Separador();
    printf("Lendo Quarto \n");
    printf("ID: ");
    scanf ("%d", &p->ID);

    printf("Camas de solteiro: \n");
    scanf("%d",&p->Cama_Solteiro);
    
    printf("Camas de casal: \n");
    scanf ("%d", &p->Cama_Casal);

    printf("Tipo de Quarto:\n Single \n Duplo \n Triplo\n");
    scanf ("s", p->Tipo_Quarto);

    printf("Preço da diaria: ");
    scanf("%f", &p->Valor_Diaria);

    p->Status = true; //se o quarto estiver disponivel    
}

//Finção para mostrar os dados dos quartos lidos
void MostrarQuarto(QUARTO p)
{
    Separador();
    printf("Exibindo quarto...\n");
    printf("ID: ");
    printf ("%u \n", p.ID);

    printf("Camas de solteiro: ");
    printf("%u \n", p.Cama_Solteiro);
    
    printf("Camas de casal: \n");
    printf("%u \n", p.Cama_Casal);

    printf("Tipo de Quarto: ");
    printf("%u\n", p.Tipo_Quarto);

    printf("Preço da diaria: ");
    printf ("%.2f\n", p.Valor_Diaria);

    printf("Status: ");
    if (!p.Status) {
        printf("Indisponível");
    } else {
        printf("Disponivel");
    }
    Separador();

}

int LerQuartoCSV(QUARTO *lista)
{
    return 0;
}

//função para gravar dados no quarto
int gravarQuartoCSV(QUARTO p)
{
    FILE *csv;
    csv = fopen(ArquivoQuartoCSV, "r + w");
    if (csv == NULL) //arquivo não existe e sera criado
    {
        printf("Criando arquivo %s\n", ArquivoQuartoCSV);
        csv = fopen(ArquivoQuartoCSV, "a");
        fprintf(csv, "ID; Solterio; Casal:Tipo de Quarto; Preço; Status\n");
        fflush(csv);
    }
    else
    {
        fseek(csv, 0, SEEK_END); 
        // arquivo ja existe e sera adicionado novos dados
        fprintf(csv, "%d;%d;%d;%s;%.2f;%d\n", p.ID, p.Cama_Solteiro, p.Cama_Casal, p.Tipo_Quarto, p.Valor_Diaria, p.Status);
        fflush(csv);
        fclose(csv);

        return 0;
    }
}

//função para  contar os quartos
int quantidadeQuartosCSV()
{
     FILE *csv;
    char linha [1000];
    csv = fopen(ArquivoQuartoCSV, "r");

    if (csv != NULL)
    {
        fscanf(csv, "%[^\n]s", linha);
        int contadorLinha = 0;
        while (fscanf(csv, "%[^\n]s", linha) != EOF)
        {
           contadorLinha++;
        }
        fclose(csv);
        return contadorLinha;
    }
    else
    {
        return 0;
    }
}

int LerQuartosCSV(QUARTO *lista)
{
    FILE *csv;
    char linha[1000];
    char *campos;
    const char s[2] = ";";
    int contadorLinha = 0;

    csv = fopen(ArquivoQuartoCSV, "r");
    if (csv != NULL)
    {   //reabrindo arquivo para ler
        fseek(csv, 0, SEEK_END);
        fscanf(csv, "%[^\n]s", linha);

        int i = 0;
        while (fscanf(csv, "%[^\n]s", linha) != EOF)
        {
            campos = strtok(linha,s);
            int CampoAtual = 0;
            while (campos != NULL)
            {
                switch (CampoAtual)
                {
                case 0:
                    lista[i].ID = atoi(campos);
                    break;
                case 1:
                    lista[i].Cama_Solteiro = atoi(campos);
                    break;
                case 2:
                    lista[i].Cama_Casal = atoi (campos);
                    break;
                case 3:
                    strcpy(lista[i].Tipo_Quarto, campos);
                    break;
                case 4:
                    lista[i].Valor_Diaria = atof(campos);
                    break;
                case 5:
                    lista[i].Status = atoi(campos);
                    break;            
                default:
                    break;
                }
                campos = strtok(NULL,s);

                CampoAtual++;
            }
        i++;  
        }
        contadorLinha = i;
        return contadorLinha;

    }
    else
    {
        printf("Arquivo não encontrado");
        return 0;
    }
}
