#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Elemento.h"

using namespace std;

class Jugador {
protected:
    string nombre;
    vector<Elemento*> mazo; 
    int cantElementos;

public:
    Jugador(const string& nom, int cantidad = 5);
    virtual ~Jugador(); 

    void generarMazoAleatorio();
    bool tieneFichasVivas();
    void mostrarMazo() const;

    virtual int elegirFicha(Elemento* fichaOponente);

    vector<Elemento*>& getMazo() { return mazo; }
    string getNombre() const { return nombre; }
};

#endif