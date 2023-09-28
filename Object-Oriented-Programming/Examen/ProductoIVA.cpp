//Carlos Ivan Armenta Naranjo A01643070
#include "ProductoIVA.h"
ProductoIVA::ProductoIVA(int codigo, string descripcion, double precio, int cantidad):Producto (codigo,descripcion,precio,cantidad){}
ProductoIVA::ProductoIVA(int codigo, string descripcion, double precio):ProductoIVA(codigo,descripcion,precio,1){}
double ProductoIVA::getImpuestos() {
    return Producto::getSubtotal() * 0.16;
}
double ProductoIVA::getTotal(){
    return (getSubtotal()+getImpuestos());
}