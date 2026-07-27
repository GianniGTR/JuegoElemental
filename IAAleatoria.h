#ifndef IAALEATORIA_H
#define IAALEATORIA_H

#include "IAEstrategica.h"
#include "Elemento.h"
#include <vector>
#include <cstdlib> 

using namespace std;

class IAAleatoria : public IAEstrategica {
public:
    int elegirFicha(const vector<Elemento*>& mazo, Elemento* fichaOponente);
};

#endif