#include "MotorDeReglas.h"

MotorDeReglas::MotorDeReglas() {

    // Agua = 0, Tierra = 1, Fuego = 2

    // Agua
    matrizDanio[0][0] = 10.0;
    matrizDanio[0][1] = 30.0;
    matrizDanio[0][2] = 50.0;

    // Tierra
    matrizDanio[1][0] = 15.0;
    matrizDanio[1][1] = 10.0;
    matrizDanio[1][2] = 20.0;

    // Fuego
    matrizDanio[2][0] = 20.0;
    matrizDanio[2][1] = 40.0;
    matrizDanio[2][2] = 10.0;
}

double MotorDeReglas::obtenerPorcentajeDanio(int atacante, int defensor) {
    return matrizDanio[atacante][defensor];
}
