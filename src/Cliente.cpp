#include "Cliente.h"

Cliente::Cliente()
{
    Estado=0;
    Posicion=0;
}

Cliente::~Cliente()
{
    //dtor
}
void Cliente::setEstado(int Valor)
{
    Estado=Valor;
}

int Cliente::getEstado()
{
    return Estado;
}

void Cliente::setPosicion(int Valor)
{
    Posicion=Valor;
}

int Cliente::getPosicion()
{
    return Posicion;
}
