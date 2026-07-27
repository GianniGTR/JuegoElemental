#include "tierra.h"
#include <iostream>

using namespace std;

Tierra::Tierra() : Elemento() {}

int Tierra::getTipoAtaque() {
    return 1;
}

int Tierra::getTipoDefensa() {
    return 1;
}

string Tierra::getNombreTipo()
{
    return "Tierra";
}
