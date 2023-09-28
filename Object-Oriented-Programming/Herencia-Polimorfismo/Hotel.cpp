#include "Hotel.h"
Hotel::Hotel(string nombre,int numJunior,int numSuite,int numDeluxe){
    this->nombre=nombre;
    int totalHabitaciones = numJunior + numSuite + numDeluxe;
    numHabitaciones = totalHabitaciones;

    for (int i = 0; i < numJunior; i++) {
        habitaciones.push_back(new habitacionJunior(100 + i));
    }

    for (int i = 0; i < numSuite; i++) {
        habitaciones.push_back(new habitacionSuite(100 + numJunior + i));
    }

    for (int i = 0; i < numDeluxe; i++) {
        habitaciones.push_back(new habitacionDeluxe(100 + numJunior+numSuite+i));
    }
};
int Hotel::checkin(string nombre, int adultos, int infantes, double credito, int tipoHabitacion) {
    int personas=adultos+infantes;
    if (tipoHabitacion == 1) {
        for (int i = 0; i < numHabitaciones; i++) {
            if(habitacionJunior*c=dynamic_cast<habitacionJunior*>(habitaciones[i])){
                if(habitaciones[i]->getDisponible()){
                    if (personas<=c->getcapacidad()) {
                        habitaciones[i]->checkin(nombre, adultos, infantes, credito);
                        return habitaciones[i]->getNumero();
                    }else{
                        return -2;
                    }
                }
        }
        }
    } else if (tipoHabitacion == 2) {
        for (int i = 0; i < numHabitaciones; i++) {
            if(habitacionSuite*c=dynamic_cast<habitacionSuite*>(habitaciones[i])){
                if(habitaciones[i]->getDisponible()){
                    if (personas<=c->getcapacidad()) {
                        habitaciones[i]->checkin(nombre, adultos, infantes, credito);
                        return habitaciones[i]->getNumero();
                    }else{
                        return -2;
                    }
                }
            }
        }
    } else if (tipoHabitacion == 3) {
        for (int i = 0; i < numHabitaciones; i++) {
            if(habitacionDeluxe*c=dynamic_cast<habitacionDeluxe*>(habitaciones[i])){
                if(habitaciones[i]->getDisponible()){
                    if (personas<=c->getcapacidad()) {
                        habitaciones[i]->checkin(nombre, adultos, infantes, credito);
                        return habitaciones[i]->getNumero();
                    }else{
                        return -3;
                    }
                }
        }
        }
    }

    return -1;
}
bool Hotel::checkout(int numHabitacion){
    for(int i=0;i<this->numHabitaciones;i++){
        if (this->habitaciones[i]->getNumero()==numHabitacion)
        {
            bool checkout=this->habitaciones[i]->checkout();
            return checkout;
        }
    }
    return false;
};
bool Hotel::realizarCargosHabitacion(int numHabitacion,double cargo){
    for(int i=0;i<this->numHabitaciones;i++){
        if(habitacionJunior*c=dynamic_cast<habitacionJunior*>(habitaciones[i])){
            if (habitaciones[i]->getNumero()==numHabitacion){
                bool exito=c->realizarCargo(cargo);
                return exito;
            }
        }
        else if(habitacionSuite*c=dynamic_cast<habitacionSuite*>(habitaciones[i])){
            if (habitaciones[i]->getNumero()==numHabitacion){
                bool exito=c->realizarCargo(cargo);
                return exito;
            }
        }
        else if(habitacionDeluxe*c=dynamic_cast<habitacionDeluxe*>(habitaciones[i])){
            if (habitaciones[i]->getNumero()==numHabitacion){
                bool exito=c->realizarCargo(cargo);
                return exito;
            }
        }
    }
    return false;
};
double Hotel::getTotalXTarifaBase(){
    double totalXTarifaBase=0;
    for(int i=0; i<this->numHabitaciones;i++){
        if (this->habitaciones[i]->getDisponible()==false){
            totalXTarifaBase=this->habitaciones[i]->getTarifaBase() + totalXTarifaBase;
        }
    }
    return totalXTarifaBase;
};
void Hotel::imprimeOcupacion(){
    cout<<"Ocupacion en "<<this->nombre<<endl;
    for(int i=0; i<this->numHabitaciones;i++){
        if (this->habitaciones[i]->getDisponible()==false){
            string ocupacion=this->habitaciones[i]->toString();
            cout<< ocupacion << endl;
        }
    }
}; 
