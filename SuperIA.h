#ifndef SUPERIA_H
#define SUPERIA_H

#include "IAEstrategica.h"
#include "MotorDeReglas.h"
#include <vector>
#include "elemento.h"

using namespace std;

class SuperIA : public IAEstrategica {
public:
    int elegirFicha(const vector<Elemento*>& mazo, Elemento* fichaOponente);
};

#endif

