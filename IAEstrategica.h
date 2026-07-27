#ifndef IAESTRATEGICA_H
#define IAESTRATEGICA_H

#include "Jugador.h"
#include "Elemento.h"
#include <vector>

using namespace std;

class IAEstrategica : public Jugador {
public:
    IAEstrategica(const string& nombre, int cantidad = 5) 
        : Jugador(nombre, cantidad) {}

    virtual ~IAEstrategica() = default;

    virtual int elegirFicha(Elemento* fichaOponente) override;
};

#endif