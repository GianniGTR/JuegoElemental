#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Elemento.h"
#include "IAEstrategica.h"
using namespace std;

class Jugador {
private:
    string nombre;
    vector<Elemento*> mazo; 
    int cantElementos;
    IAEstrategica* cerebro; 

public:
    Jugador(const string& nom, int cantidad = 5);
    virtual ~Jugador(); 

    void generarMazoAleatorio();
    bool tieneFichasVivas();
    void mostrarMazo();
  
    int elegirFicha(Elemento* fichaOponente);

    vector<Elemento*>& getMazo() { return mazo; }
    void setEstrategia(IAEstrategica* e) { cerebro = e; }
};

#endif
