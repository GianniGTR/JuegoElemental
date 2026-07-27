#include "SuperIA.h"

int SuperIA::elegirFicha(Elemento* fichaOponente) {
    MotorDeReglas motor;
    int mejorIndiceEstrategico = -1;
    double maxDanio = -1.0;

    for (size_t i = 0; i < mazo.size(); i++) {
        if (mazo[i]->getEnergia() > 0) {
            double danioPosible = motor.obtenerPorcentajeDanio(
                mazo[i]->getTipoAtaque(), 
                fichaOponente->getTipoDefensa()
            );

            if (danioPosible >= fichaOponente->getEnergia()) {
                return static_cast<int>(i); // Remata al oponente inmediatamente
            }

            if (danioPosible > maxDanio) {
                maxDanio = danioPosible;
                mejorIndiceEstrategico = static_cast<int>(i);
            }
        }
    }
    return mejorIndiceEstrategico;
}