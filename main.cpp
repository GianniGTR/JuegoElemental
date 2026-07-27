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
    cout << "      JUEGO ELEMENTAL\n";
    cout << "=================================\n\n";

    // Crear jugadores
    Jugador* humano = new Jugador("Jugador");
    Jugador* cpu = new Jugador("Computadora");

    // Asignar estrategia a la IA
    cout<<"Elija la dificultad de la IA: "<<endl;
    cout<<"1. IA aleatoria (Facil)"<<endl;
    cout<<"2. IA estrategica (Normal)"<<endl;
    cout<<"3. Super IA (Dificil)"<<endl;
    cin>>opcionIA;

    switch(opcionIA){
        case 1:
        cpu->setEstrategia(new IAAleatoria());
        break;
        
        case  2: 
        cpu->setEstrategia(new IAEstrategica());
        break;

        case 3:
        cpu->setEstrategia(new SuperIA());
        break;

        default:
        cpu->setEstrategia(new IAAleatoria());
        break;
    }

    // Generar mazos
    humano->generarMazoAleatorio();
    cpu->generarMazoAleatorio();

    cout << "Mazos generados correctamente.\n\n";

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

     if (fichaJugador < 0 || fichaJugador >= humano->getMazo().size()){

    cout << "Indice invalido.\n";
    continue;

}

if (humano->getMazo()[fichaJugador]->getEnergia() <= 0){

    cout << "Esa ficha ya fue derrotada.\n";
    continue;
}

    int fichaIA = cpu->elegirFicha(humano->getMazo()[fichaJugador]);

    if (fichaIA == -1)
{
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

if (ganador == 1){
    cout << "¡GANASTE!"<<endl;
}else{
    cout << "Perdiste"<<endl;
}

    delete humano;
    delete cpu;

    return 0;
}
