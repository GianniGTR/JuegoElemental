#ifndef AGUA_H
#define AGUA_H

#include "elemento.h"

class Agua : public Elemento {
public:
    Agua();
    string getNombreTipo () override;
    int getTipoAtaque() override;
    int getTipoDefensa() override;
};

#endif