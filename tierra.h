#ifndef TIERRA_H
#define TIERRA_H

#include "Elemento.h"

class Tierra : public Elemento {
public:
    Tierra();
    string getNombreTipo () override;
    int getTipoAtaque() override;
    int getTipoDefensa() override;
};

#endif

