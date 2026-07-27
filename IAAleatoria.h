#ifndef IAALEATORIA_H
#define IAALEATORIA_H

#include "IAEstrategica.h"
#include "Elemento.h"
#include <vector>
#include <cstdlib> 

using namespace std;

class IAAleatoria : public IAEstrategica {
public:
    IAAleatoria(const string& nombre, int cantidad = 5) 
        : IAEstrategica(nombre, cantidad) {}

    int elegirFicha(Elemento* fichaOponente) override;
};

#endif