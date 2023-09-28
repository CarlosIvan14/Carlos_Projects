#include "Habitacion.h"
#include<iostream>
#include<string>
using namespace std;
Habitacion::Habitacion(){
        this->numero=0;
        this->nombre=' ';
        this->adultos=0;
        this->infantes=0;
        this->credito=0;
        this->cargo=0;
        this->disponible=true;
    }
Habitacion::Habitacion(int numero){
        this->numero=numero;
        this->disponible=true;
        this->nombre=' ';
        this->adultos=0;
        this->infantes=0;
        this->credito=0;
        this->cargo=0;
    }
int Habitacion::getNumero(){
        return this->numero;
    }
bool Habitacion::getDisponible(){
        return this->disponible;
    }
bool Habitacion::checkin(string nombre, int adultos, int infantes, double credito){
        if(this->disponible==true){
        this->nombre=nombre;
        this->adultos=adultos;
        this->infantes=infantes;
        this->credito=credito;
        this->disponible=false;
        this->cargo=0;
        return true;
    }
    else{
        return false;
    }
    }
bool Habitacion::checkout(){

      if (disponible==false){
            this->adultos=0;
            this->infantes=0;
            this->cargo=0;
            this->credito=0;
            this->disponible=true;
            return true;
        }
        else{
            return false;
        }
    }
bool Habitacion::realizarCargo(double cargo){
    if(this->disponible==false){
        if ((cargo>0)&&(cargo+this->cargo<=this->credito)){
            this->cargo=this->cargo+cargo;
            return true;
        }
        else{
            return false;
        }
    }else{
        return false;
    }
    }
     

