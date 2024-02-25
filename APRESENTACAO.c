#include <stdio.h>
#include <stdlib.h>
#include "APRESENTACAO.h"

const int TamSeparador = 40;

void Separador()
{
    for (int i = 0 ; i< TamSeparador; i++ )
        printf("#");
    printf("\n");
}

int MenuPrincipal (){
    int Opcao;
    //system("clear");
    Separador();
    printf("1.RESERVAS\n2.CLIENTES\n3. HOSPEDAGEM\n 4.QUARTOS\n 0. SAIR");
    Separador();
    Separador();
    Separador();
    printf("\nOpção -> ");
    scanf(" %d", &Opcao);
    return Opcao;
}