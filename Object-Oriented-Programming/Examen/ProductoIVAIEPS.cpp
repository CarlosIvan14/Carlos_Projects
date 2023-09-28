//Carlos Ivan Armenta Naranjo A01643070
#include "ProductoIVAIEPS.h"
ProductoIVAIEPS::ProductoIVAIEPS(int codigo, string descripcion, double precio, int cantidad, int ml):ProductoIVA(codigo,descripcion,precio,cantidad){
    this->ml=ml;
}
ProductoIVAIEPS::ProductoIVAIEPS(int codigo, string descripcion, double precio, int ml):ProductoIVAIEPS(codigo,descripcion,precio,1,ml){}
double ProductoIVAIEPS::getIEPS(){
    return (this->ml*this->cantidad*this->IEPSxLT)/1000;
};
double ProductoIVAIEPS::getImpuestos(){
    return ((getSubtotal())*(.16)+getIEPS());
}

double ProductoIVAIEPS::getTotal(){
    return (getSubtotal()+getImpuestos());
}
