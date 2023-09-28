//Carlos Ivan Armenta Naranjo A01643070
#ifndef PRODUCTOIVA_H
#define PRODUCTOIVA_H
#include "Producto.h"
#include<iostream>
#include<string>
using namespace std;
class ProductoIVA:public Producto{
    public:
        ProductoIVA(int codigo, string descripcion, double precio, int cantidad);
        ProductoIVA(int codigo, string descripcion, double precio);
        double getImpuestos();
        double getTotal(); 
};
#endif