#include "fuego.h"
#include <iostream>

using namespace std;

Fuego::Fuego() : Elemento() {}

int Fuego::getTipoAtaque() {
    return 2;
}

int Fuego::getTipoDefensa() {
    return 2;
}

string Fuego::getNombreTipo()
{
    return "Fuego";
}
