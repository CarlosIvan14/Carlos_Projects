//Carlos Ivan Armenta Naranjo A01643070
#include "Producto.h"
Producto::Producto(int codigo, string descripcion, double precio, int cantidad){
    this->codigo=codigo;
    this->descripcion=descripcion;
    if(precio>0){
        this->precio=precio;
    }else{
        this->precio=1;
    }
    if(cantidad>=1 && cantidad<=10){
        this->cantidad=cantidad;
    }else{
        this->cantidad=1;
    }

}
Producto::Producto(int codigo, string descripcion, double precio){
    this->codigo=codigo;
    this->descripcion=descripcion;
    if(precio>0){
        this->precio=precio;
    }else{
        this->precio=1;
    }
    this->cantidad=1;
}
double Producto::getSubtotal(){
    return (cantidad*precio);
}
double Producto::getImpuestos() {
    return 0;
}
double Producto::getTotal(){
    return (getSubtotal()+getImpuestos());
}