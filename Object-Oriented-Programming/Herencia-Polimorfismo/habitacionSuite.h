#ifndef HABITACIONSUITE_H
#define HABITACIONSUITE_H
#include "Habitacion.h"
#include<iostream>
#include<string>
using namespace std;
class habitacionSuite:public Habitacion{
    private:
        int capacidad;
    public:
        habitacionSuite(int numHabitacion);
        habitacionSuite();
        double getTarifaBase();
        string toString();
        int getcapacidad();
};
#endif 