#ifndef __CLIENTE_H__
#define __CLIENTE_H__
#include <stdlib.h>

#include "DATA.h"

typedef struct Cliente
{
    char CPF[14];
    char nome[50];
    DATA dataNascimento;
    int idade;
    char endereco[100];
    char cidade[100];
    char estado[10];
    unsigned int pontos;
} Cliente;

//menu para reservas de quartos
int Menu_Reservas()
{
    int Opção;
    system("clear");

    printf("\n1. Mostrar Quartos\n2. Reservar Quartos");
    scanf("%d", &Opção);

    return Opção;
}

#endif