#ifndef HABITACION_H
#define HABITACION_H
#include<iostream>
#include<string>
using namespace std;

class Habitacion
{
protected:
    int numero;
    string nombre;
    int adultos;
    int infantes;
    double credito;
    double cargo;
    bool disponible;
public:
    Habitacion();
    Habitacion(int numero);
    int getNumero();
    bool getDisponible();
    bool checkin(string nombre, int adultos, int infantes, double credito);
    bool checkout();
    virtual double getTarifaBase()=0;
    bool realizarCargo(double cargo);
    virtual string toString()=0;

};
#endif
 

