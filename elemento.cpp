#include "elemento.h"
#include <iostream>

using namespace std;

Elemento::Elemento() : energia(100.0)
{
}

Elemento::~Elemento()
{
}

void Elemento::recibirDanio(double danio)
{
    energia -= danio;

    if (energia <= 0)
        energia = 0;
}

double Elemento::getEnergia() const
{
    return energia;
}
