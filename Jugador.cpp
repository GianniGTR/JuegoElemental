#include "Jugador.h"
#include "Agua.h"
#include "Fuego.h"
#include "Tierra.h"
#include <cstdlib> 
#include <iostream>

using namespace std;

Jugador::Jugador(const string& nom, int cantidad)
    : nombre(nom), cantElementos(cantidad)
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

void Jugador::mostrarMazo() const
{
    cout << "Mazo de " << nombre << endl;

    for (size_t i = 0; i < mazo.size(); i++)
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
    int opcion = -1;
    mostrarMazo();

    do {
        cout << nombre << ", ingresa el indice de la ficha que quieres jugar: ";
        cin >> opcion;

        if (opcion < 0 || opcion >= static_cast<int>(mazo.size())) {
            cout << "Indice invalido. Intenta de nuevo." << endl;
        } else if (mazo[opcion]->getEnergia() <= 0) {
            cout << "Esa ficha esta derrotada. Elige otra." << endl;
        } else {
            break; 
        }
    } while (true);

    return opcion;
}