#ifndef SUPERIA_H
#define SUPERIA_H

#include "IAEstrategica.h"
#include "MotorDeReglas.h"
#include "Elemento.h"
#include <vector>

using namespace std;

class SuperIA : public IAEstrategica {
public:
    SuperIA(const string& nombre, int cantidad = 5) 
        : IAEstrategica(nombre, cantidad) {}

    int elegirFicha(Elemento* fichaOponente) override;
};

#endif