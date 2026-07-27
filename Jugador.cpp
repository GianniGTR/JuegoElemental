#include "Jugador.h"
#include "Agua.h"
#include "Fuego.h"
#include "Tierra.h"
#include <cstdlib> 
#include <iostream>

using  namespace std;

Jugador::Jugador(const string& nom, int cantidad)
    : nombre(nom), cantElementos(cantidad), cerebro(nullptr)
{
}
Jugador::~Jugador() {
   
    for (Elemento* e : mazo) {
        delete e;
    }
    mazo.clear();
}

void Jugador::generarMazoAleatorio() {
    for (int i = 0; i < cantElementos; ++i) {
        int tipo = std::rand() % 3;
        if (tipo == 0) mazo.push_back(new Agua());
        else if (tipo == 1) mazo.push_back(new Tierra());
        else mazo.push_back(new Fuego());
    }
}

void Jugador::mostrarMazo()
{
    cout << "Mazo de " << nombre << endl;

    for (int i = 0; i < mazo.size(); i++)
    {
        cout << i << " - "
             << mazo[i]->getNombreTipo();

        if (mazo[i]->getEnergia() <= 0)
        {
            cout << "  [DERROTADA]";
        }
        else
        {
            cout << "  Energia: "
                 << mazo[i]->getEnergia()
                 << "%";
        }

        cout << endl;
    }
}

bool Jugador::tieneFichasVivas() {
    
    for (Elemento* e : mazo) {
        if (e->getEnergia() > 0) return true;
    }
    return false;
}

int Jugador::elegirFicha(Elemento* fichaOponente) {
    if (cerebro != NULL) {
       
        return cerebro->elegirFicha(mazo, fichaOponente);
    }
    
    return -1; 
}
