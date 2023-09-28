#ifndef HOTEL_H
#define HOTEL_H
#include "Habitacion.h"
#include "habitacionJunior.h"
#include "habitacionSuite.h"
#include "habitacionDeluxe.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Hotel
{
private:
    vector<Habitacion*> habitaciones;
    int numHabitaciones;
    string nombre;
public:
    Hotel(string nombre,int numJunior,int numSuite,int numDeluxe);
    int checkin(string nombre, int adultos, int infantes, double credito, int tipoHabitacion);
    bool checkout(int numHabitacion);
    bool realizarCargosHabitacion(int numHabitacion,double cargo);
    double getTotalXTarifaBase();
    void imprimeOcupacion();
};
#endif 
 
