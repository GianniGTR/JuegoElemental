#ifndef MOTOR_DE_REGLAS_H
#define MOTOR_DE_REGLAS_H

class MotorDeReglas {
private:
    // 3 atacantes x 3 defensores
    double matrizDanio[3][3];

public:
    MotorDeReglas();
    double obtenerPorcentajeDanio(int atacante, int defensor);
};

#endif // MOTOR_DE_REGLAS_H