#include <stdio.h>
#include "Cliente.h"
//c para ponteiro de cliente
void AdicionarPontosCliente( Cliente *c, int pontos )
{
    c->pontos += pontos;
}