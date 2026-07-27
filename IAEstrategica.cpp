#include "IAEstrategica.h"
#include "MotorDeReglas.h"

int IAEstrategica::elegirFicha(Elemento* fichaOponente) {
    MotorDeReglas motor;
    int mejorIndice = -1;
    double maxDanio = -1.0;

    for (size_t i = 0; i < mazo.size(); i++) {
        if (mazo[i]->getEnergia() > 0) {
            double danioPosible = motor.obtenerPorcentajeDanio(
                mazo[i]->getTipoAtaque(), 
                fichaOponente->getTipoDefensa()
            );

            if (danioPosible > maxDanio) {
                maxDanio = danioPosible;
                mejorIndice = i;
            }
        }
    }
    return mejorIndice;
}