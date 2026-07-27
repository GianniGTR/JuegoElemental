#include "IAAleatoria.h"

int IAAleatoria::elegirFicha(Elemento* fichaOponente) {

    vector<int> vivos;

    for (size_t i = 0; i < mazo.size(); i++) {
        if (mazo[i]->getEnergia() > 0) {
            vivos.push_back(i); 
        }
    }

    if (vivos.empty()) {
        return -1;
    }

    int indiceAleatorio = rand() % vivos.size();
    
    return vivos[indiceAleatorio];
}