#ifndef IAESTRATEGICA_H
#define IAESTRATEGICA_H

#include <vector>
#include "Elemento.h"

using namespace std;

class IAEstrategica
{
public:
    virtual ~IAEstrategica() = default;

    virtual int elegirFicha(
        const vector<Elemento*>& mazo,
        Elemento* fichaOponente);
};

#endif
