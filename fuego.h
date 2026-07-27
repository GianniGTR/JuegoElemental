#ifndef FUEGO_H
#define FUEGO_H

#include "elemento.h"

class Fuego : public Elemento {
public:
    Fuego();
    
    string getNombreTipo () override;
    int getTipoAtaque() override;
    int getTipoDefensa() override;
};

#endif