#ifndef PARTIDA_H
#define PARTIDA_H

#include "Jugador.h"
#include "MotorDeReglas.h"
#include <vector>
using namespace std;

class Partida {
private:
    Jugador* jugadorHumano;   
    Jugador* jugadorPC;       
    MotorDeReglas reglas;     
    int turnoActual;

public:
    Partida(Jugador* h, Jugador* p);
    ~Partida(); 

    void resolverTurno(int indiceHumano, int indicePC);

    int evaluarGanadorFinal();

    Jugador* getHumano() { return jugadorHumano; }
    Jugador* getPC() { return jugadorPC; }
};

#endif
