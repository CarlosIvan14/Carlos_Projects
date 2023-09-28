#ifndef HABITACIONDELUXE_H
#define HABITACIONDELUXE_H
#include "Habitacion.h"
#include<iostream>
#include<string>
using namespace std;
class habitacionDeluxe:public Habitacion{
    private:
        int capacidad;
    public:
        habitacionDeluxe(int numHabitacion);
        habitacionDeluxe();
        double getTarifaBase();
        string toString();
        int getcapacidad();
};
#endif 