#include "habitacionJunior.h"
#include<iostream>
#include<string>
using namespace std;
habitacionJunior::habitacionJunior(int numHabitacion):Habitacion(numHabitacion){
    this->capacidad=4;
}
habitacionJunior::habitacionJunior():habitacionJunior(0){}
double habitacionJunior::getTarifaBase(){
    double tarifaBase= (this->adultos*450.00)+(this->infantes*150.00);
    tarifaBase=tarifaBase+tarifaBase*0.20;
        return tarifaBase;
}
string habitacionJunior::toString(){
    return to_string(this->numero) + ",Huesped:" + this->nombre + ",Tarifa Base:" + to_string(getTarifaBase()) +
    ",Credito:" + to_string(this->credito) + ",Cargos:" + to_string(this->cargo)+",Habitacion Junior";
}
int habitacionJunior::getcapacidad(){
    return this->capacidad;
} 