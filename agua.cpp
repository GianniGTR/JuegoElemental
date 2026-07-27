#include "Agua.h"
#include <iostream>

using namespace std;

Agua::Agua() : Elemento() {}

int Agua::getTipoAtaque() {
    return 0;
}

int Agua::getTipoDefensa() {
    return 0;
}

string Agua::getNombreTipo()
{
    return "Agua";
}