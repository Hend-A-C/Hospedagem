#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "RESERVA.h"
#include "APRESENTACAO.h"

//menu para reservas de quartos
int Menu_Reservas()
{
    int opção;
    system("clear");

    printf("\n1. Mostrar Quartos\n2. Reservar Quartos");
    scanf("%d", &opção);

    return opção;
}

/*ID a ser utilizado em novo cadatro de reserva*/
unsigned int ProximoID_Reserva()
{
    char ArquivoReserva[] = ("ID_Reserva.dat");
    FILE *f = fopen(ArquivoReserva, "r + w");

    unsigned ID = 1;
    unsigned int v;
    int size;

    if (f != NULL)
    {
        size = fread(&v, sizeof(unsigned int), 1, f);
        if (size > 0)
        {
            v++;
            ID = v;
        }
        fseek(f, 0, SEEK_SET);
        fwrite (&v, sizeof(unsigned int), 1, f);
        fflush(f);
        fclose(f);
    }
    else
    {
        f = fopen(ArquivoReserva, "wb");
        fwrite(&ID, sizeof(unsigned int), 1,f);
        fclose(f);
    }
    return ID;
}

/*  função para gravar a reserva*/
/* @return retoma  as informações da reserva*/

RESERVA ReservarQuarto(DATA Checkin, DATA Checkout, char *TipoQuarto)
{
    RESERVA R;
    R.ID = 0;
    R.Checkin = Checkin;
    R.Checkout = Checkout;
    strcpy(R.TipoQuarto, TipoQuarto);
    return R;
}
/*Exibir a reserva*/

void MostrarReserva (RESERVA R)
{
    char ci[15], co[15];
    DataToString(R.Checkin, ci, false);
    DataToString(R.Checkout,co, false);

    Separador();
    printf("Reserva ID: %u\n", R.ID);
    printf("Quarto reservado: %u\n", R.ID_Quarto);
    printf("Data do check in: %s\n", ci);
    printf("Data check out: %s\n", co);
    printf("Tipo do Quarto: %s\n", R.TipoQuarto);
    Separador();
}
