#include "IAAleatoria.h"

int IAAleatoria::elegirFicha(const vector<Elemento*>& mazo, Elemento* fichaOponente) {

    vector<int> vivos;

    for (int i = 0; i < mazo.size(); i++) {
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
