#include "Barbero.h"

Barbero::Barbero() //Inicializa Estado y Posicion en 0
{
    Estado=0;
    Posicion=0;
}

Barbero::~Barbero()
{
    //dtor
}
void Barbero::setEstado(int Valor) //Recibe un Valor y se lo asigna a Estado
{
    Estado=Valor;
}

int Barbero::getEstado() //Devuelve el Estado
{
    return Estado;
}

void Barbero::setPosicion(int Valor) //Recibe un Valor y se lo asigna a Posicion
{
    Posicion=Valor;
}

int Barbero::getPosicion() //Devuelve la Posicion
{
    return Posicion;
}
