#include "habitacionSuite.h"
#include<iostream>
#include<string>
using namespace std;
habitacionSuite::habitacionSuite(int numHabitacion):Habitacion(numHabitacion){
    this->capacidad=6;
}
habitacionSuite::habitacionSuite():habitacionSuite(0){}
double habitacionSuite::getTarifaBase(){
    double tarifaBase= (this->adultos*450.00)+(this->infantes*150.00);
    tarifaBase=tarifaBase+tarifaBase*0.30;
        return tarifaBase;
}
string habitacionSuite::toString(){
    return to_string(this->numero) + ",Huesped:" + this->nombre + ",Tarifa Base:" + to_string(getTarifaBase()) +
    ",Credito:" + to_string(this->credito) + ",Cargos:" + to_string(this->cargo)+",Habitacion Suite";
}
int habitacionSuite::getcapacidad(){
    return this->capacidad;
} 