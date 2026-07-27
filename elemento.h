#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <string>

using namespace std;

class Elemento
{
protected:
    double energia;

public:
    Elemento();
    virtual ~Elemento();

    void recibirDanio(double porcentaje);
    double getEnergia() const;

    virtual string getNombreTipo() = 0;

    virtual int getTipoAtaque() = 0;
    virtual int getTipoDefensa() = 0;
};

#endif
