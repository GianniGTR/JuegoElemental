#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Jugador.h"
#include "Partida.h"
#include "IAAleatoria.h"
#include "IAEstrategica.h"
#include "SuperIA.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    int opcionIA;

    cout << "=================================\n";
    cout << "       JUEGO ELEMENTAL\n";
    cout << "=================================\n\n";

    cout << "Elija la dificultad de la IA: " << endl;
    cout << "1. IA aleatoria (Facil)" << endl;
    cout << "2. IA estrategica (Normal)" << endl;
    cout << "3. Super IA (Dificil)" << endl;
    cin >> opcionIA;

    Jugador* humano = new Jugador("Jugador");

    Jugador* cpu = nullptr;

    switch (opcionIA) {
        case 1:
            cpu = new IAAleatoria("Computadora");
            break;
        case 2:
            cpu = new IAEstrategica("Computadora");
            break;
        case 3:
            cpu = new SuperIA("Computadora");
            break;
        default:
            cpu = new IAAleatoria("Computadora");
            break;
    }

    // Generar mazos
    humano->generarMazoAleatorio();
    cpu->generarMazoAleatorio();

    cout << "\nMazos generados correctamente.\n\n";

    cout << "\n---------------- JUGADOR ----------------\n";
    humano->mostrarMazo();

    cout << "\n-------------- COMPUTADORA --------------\n";
    cpu->mostrarMazo();

    Partida partida(humano, cpu);

    while (partida.evaluarGanadorFinal() == 0)
    {
        int fichaJugador;

        cout << "\n===== TU TURNO =====\n";
        humano->mostrarMazo();

        cout << "Elegi una ficha: ";
        cin >> fichaJugador;

        if (fichaJugador < 0 || fichaJugador >= static_cast<int>(humano->getMazo().size())) {
            cout << "Indice invalido.\n";
            continue;
        }

        if (humano->getMazo()[fichaJugador]->getEnergia() <= 0) {
            cout << "Esa ficha ya fue derrotada.\n";
            continue;
        }

        int fichaIA = cpu->elegirFicha(humano->getMazo()[fichaJugador]);

        if (fichaIA == -1) {
            cout << "La computadora no tiene fichas disponibles.\n";
            break;
        }

        cout << "La IA eligio la ficha " << fichaIA << endl;

        partida.resolverTurno(fichaJugador, fichaIA);

        cout << "\nEstado del jugador:\n";
        humano->mostrarMazo();

        cout << "\nEstado de la IA:\n";
        cpu->mostrarMazo();
    }

    int ganador = partida.evaluarGanadorFinal();

    if (ganador == 1) {
        cout << "\n¡GANASTE!" << endl;
    } else {
        cout << "\nPerdiste" << endl;
    }

    // Liberacion de memoria
    delete humano;
    delete cpu;

    return 0;
}