#ifndef __QUARTO_H__
#define __QUARTO_H__

#include <stdio.h>
#include <stdbool.h>
#include "DATA.h"

typedef struct QUARTO
{
    unsigned int ID;
    unsigned int Cama_Solteiro;
    unsigned int Cama_Casal;
    char Tipo_Quarto [8];
    float Valor_Diaria;
    bool Status;
} QUARTO;

void LerQuarto(QUARTO *p ); //Ponteiro para registro de quarto

void MostrarQuarto(QUARTO p); //exibir registro do tipo quarto

int GravarQuartoCSV (QUARTO);

int QndQuartoCSV();

int LerQuartoCSV(QUARTO *lista); //leitura  do vetor e quantidade de quartos

int GravarQuartoDAT (QUARTO p);

int QndQuartoDAT ();

int LerQuartoDAT( QUARTO *lista);

int buscarTipoQuarto(char *Tipo_Quarto, QUARTO *listaEntrada, int QndQuarto, QUARTO *listaSaida);

#endif