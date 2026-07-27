#include "SuperIA.h"

int SuperIA::elegirFicha(const vector<Elemento*>& mazo, Elemento* fichaOponente) {
    MotorDeReglas motor;
    int mejorIndiceEstrategico = -1;
    double maxDanio = -1.0;

    for (int i = 0; i < mazo.size(); i++) {
        if (mazo[i]->getEnergia() > 0) {
            double danioPosible = motor.obtenerPorcentajeDanio(mazo[i]->getTipoAtaque(), fichaOponente->getTipoDefensa());

            // --- Lógica de Eficiencia (Super IA) ---
            // Si el daño que hace mi ficha es mayor o igual a la vida que le queda al humano, la elijo ya mismo
            if (danioPosible >= fichaOponente->getEnergia()) {
                return i; // Remata al oponente inmediatamente
            }

            // --- Lógica Estratégica de respaldo ---
            if (danioPosible > maxDanio) {
                maxDanio = danioPosible;
                mejorIndiceEstrategico = i;
            }
        }
    }
    return mejorIndiceEstrategico;
}
