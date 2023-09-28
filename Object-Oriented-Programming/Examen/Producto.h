//Carlos Ivan Armenta Naranjo A01643070
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<iostream>
#include<string>
using namespace std;
class Producto{
    protected:
        int codigo;
        string descripcion;
        double precio;
        int cantidad;
    public:
        Producto(int codigo, string descripcion, double precio, int cantidad);
        Producto(int codigo, string descripcion, double precio);
        double getSubtotal();
        virtual double getImpuestos();
        virtual double getTotal();
};
#endif