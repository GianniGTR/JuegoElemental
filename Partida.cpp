#include "Partida.h"
#include <iostream>

using namespace std;

Partida::Partida(Jugador* h, Jugador* p) : jugadorHumano(h), jugadorPC(p), turnoActual(1) {}

void Partida::resolverTurno(int indiceHumano, int indicePC) {

    cout << "\n=====================================\n";
    cout << "             TURNO " << turnoActual << endl;
    cout << "=====================================\n";

    Elemento* elHumano = jugadorHumano->getMazo()[indiceHumano];
    Elemento* elPC = jugadorPC->getMazo()[indicePC];

    cout << "\nJugador eligio: "
     << elHumano->getNombreTipo() << endl;

    cout << "Computadora eligio: "
     << elPC->getNombreTipo() << endl;



    double danioParaPC = reglas.obtenerPorcentajeDanio(elHumano->getTipoAtaque(), elPC->getTipoDefensa());
    double danioParaHumano = reglas.obtenerPorcentajeDanio(elPC->getTipoAtaque(), elHumano->getTipoDefensa());

    elPC->recibirDanio(danioParaPC);
    elHumano->recibirDanio(danioParaHumano);

        if (elPC->getEnergia() == 0)
    {
    cout << "La ficha "
         << elPC->getNombreTipo()
         << " de la IA fue derrotada." << endl;
    }

    if (elHumano->getEnergia() == 0)
    {
    cout << "Tu ficha "
         << elHumano->getNombreTipo()
         << " fue derrotada." << endl;
    }


    cout << elHumano->getNombreTipo()
     << " hizo "
     << danioParaPC
     << " puntos de dano." << endl;
    cout << elPC->getNombreTipo()
     << " hizo "
     << danioParaHumano
     << " puntos de dano." << endl;

    turnoActual++;
}

int Partida::evaluarGanadorFinal() {
    bool humanoVivo = jugadorHumano->tieneFichasVivas();
    bool pcVivo = jugadorPC->tieneFichasVivas();

    if (humanoVivo && !pcVivo) return 1; 
    if (!humanoVivo && pcVivo) return 2; 
    return 0; 
}

Partida::~Partida()
{
}