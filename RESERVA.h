#ifndef __RESERVA_H__
#define __RESERVA_H__

#include "DATA.h"

typedef struct RESERVA
{
    unsigned int ID;
    char CPF[14];
    DATA Checkin;
    DATA Checkout;
    char TipoQuarto[8]; //single, Duplo ou Triplo
    unsigned int ID_Quarto;
} RESERVA;

unsigned int ProximoID_Reserva();

RESERVA ReservarQuarto(DATA Checkin, DATA Checkout, char *TipoQuarto); //trazer dados de um querto reservado

void MostrarReserva(RESERVA R);

#endif
