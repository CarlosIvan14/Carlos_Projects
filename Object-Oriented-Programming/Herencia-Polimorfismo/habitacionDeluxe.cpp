#include "habitacionDeluxe.h"
#include<iostream>
#include<string>
using namespace std;
habitacionDeluxe::habitacionDeluxe(int numHabitacion):Habitacion(numHabitacion){
    this->capacidad=8;
}
habitacionDeluxe::habitacionDeluxe():habitacionDeluxe(0){}
double habitacionDeluxe::getTarifaBase(){
    double tarifaBase= (this->adultos*450.00)+(this->infantes*150.00);
    tarifaBase=tarifaBase+tarifaBase*0.50;
        return tarifaBase;
}
string habitacionDeluxe::toString(){
    return to_string(this->numero) + ",Huesped:" + this->nombre + ",Tarifa Base:" + to_string(getTarifaBase()) +
    ",Credito:" + to_string(this->credito) + ",Cargos:" + to_string(this->cargo)+",Habitacion Deluxe";
}
int habitacionDeluxe::getcapacidad(){
    return this->capacidad;
} 