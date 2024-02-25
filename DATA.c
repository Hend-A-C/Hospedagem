#include "DATA.h"
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "time.h"

// dias em segundos
const int SegundosDias = 86400;

//função para  converter str para tipo data

void StringToData(char *str, DATA *Data)
{
    int i = 0, c = 0;
    char tmp[5];
    while (str[i] != '/')
    {
        tmp[c++] = str[i++];
    }
    tmp[c] = 0;
    Data ->dia = atoi(tmp);

    //reinicia o loop para  mes
    c = 0;
    i++;
    while( str[i] != '/')
    {
        tmp[c++] = str[i++];
    }
    tmp[c] = 0;
    Data->mes = atoi(tmp);

    //reinicia o loop para ano
    c = 0;
    i++;
    while( str[i] != 0)
    {
        tmp[c++] = str[i++];
    }
    tmp[c] = 0;
    Data->ano = atoi(tmp);
    Data->hora = 0;
    Data->minuto=0;
    Data->segundo=0;
}

//funcao para data do dia
DATA hoje(){
    struct tm *instante ;
    DATA d;
    time_t result = time(NULL);
    instante = localtime(&result);
    //strcpy(instante, ctime(&result));
    // printf("Agora: %s");
    // distribuindo
    d.hora = instante->tm_hour;
    d.minuto = instante->tm_min;
    d.segundo = instante->tm_sec;
    d.ano = instante->tm_year + 1900;
    d.mes = instante->tm_mon + 1;
    d.dia = instante->tm_mday;
    return d;
}

int DataToString(DATA p, char *output, bool complete)
{
    if (complete == false)
        sprintf(output,"%02d\\%02d\\%d", p.dia, p.mes, p.ano);
    else
        sprintf(output,"%02d:%02d:%02d %02d\\%02d\\%d", p.hora,p.minuto, p.segundo, p.dia, p.mes, p.ano);

    return strlen(output);
}


int comparaValor(int t)
{
    if (t == 0 )
        return 0;
    else if ( t > 0 )
        return 1;
    else return -1;
}

/**
 * Compara duas datas e retorna 0 se as datas forem iguais
 * ou um valor positivo se a data d1 for mais recente que d2 e negativo caso contrário
 * @param d1 variável do tipo DATA para comparação
 * @param d2 variável do tipo DATA para comparação
 * @return retorna 0 se as datas forem iguais, 1 se a data d1 for mais recente que d2
 * e -1 caso contrário
*/
int DataCmp(DATA d1, DATA d2)
{
    int tmp;
    tmp = d1.ano - d2.ano;
    tmp = comparaValor(tmp);
    if (tmp != 0)
        return tmp;
    tmp = d1.mes - d2.mes;
    tmp = comparaValor(tmp);
    if (tmp != 0)
        return tmp;
    tmp = d1.dia - d2.dia;
    tmp = comparaValor(tmp);
    return tmp;
}


/**
 * Retorna a diferença em dias entre duas datas
 * @param d1 variável do tipo DATA para comparação
 * @param d2 variável do tipo DATA para comparação*/
int DataDiff(DATA d2, DATA d1)
{
    struct tm d1_tm, d2_tm ;
    // convertendo dia2
    d2_tm.tm_hour = d2.hora;
    d2_tm.tm_min = d2.minuto;
    d2_tm.tm_sec = d2.segundo;
    d2_tm.tm_year = d2.ano;
    d2_tm.tm_mon = d2.mes-1;
    d2_tm.tm_mday = d2.dia;

    // convertendo dia1
    d1_tm.tm_hour = d1.hora;
    d1_tm.tm_min = d1.minuto;
    d1_tm.tm_sec = d1.segundo;
    d1_tm.tm_year = d1.ano;
    d1_tm.tm_mon = d1.mes-1;
    d1_tm.tm_mday = d1.dia;

    time_t d1_t, d2_t;
    // convertendo datas para time_t
    d1_t = mktime(&d1_tm);
    d2_t = mktime(&d2_tm);
    double ret = difftime(d2_t, d1_t);
    int tempo = round(ret);
    int dias = tempo / SegundosDias;
    return dias;
}