#ifndef __TEMPO_H__
#define __TEMPO_H__

#include <stdbool.h>



/* Definição de um registro para armazenar as datas
*/
typedef struct DATA
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
} DATA ;



//Função que converte texto para o tipo DATA

void StringToData(char *str, DATA *data);



DATA hoje();

int DataToString(DATA p, char *output, bool complete);

int DataCmp(DATA d1, DATA d2);

int DataDiff(DATA d1, DATA d2);

#endif