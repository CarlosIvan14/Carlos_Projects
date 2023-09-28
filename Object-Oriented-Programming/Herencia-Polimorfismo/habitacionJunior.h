#ifndef HABITACIONJUNIOR_H
#define HABITACIONJUNIOR_H
#include "Habitacion.h"
#include<iostream>
#include<string>
using namespace std;
class habitacionJunior:public Habitacion{
    private:
        int capacidad;
    public:
        habitacionJunior(int numHabitacion);
        habitacionJunior();
        double getTarifaBase();
        string toString();
        int getcapacidad();
};
#endif 