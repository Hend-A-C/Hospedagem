
#include <stdio.h>
#include <stdlib.h>
#include "APRESENTACAO.h"
#include "Cliente.h"
#include "DATA.h"
#include "QUARTO.h"
#include "RESERVA.h"

int main(){
    Menu_Principal();

    switch (Menu_Principal())
        case 1:
            Menu_Reservas();


}
