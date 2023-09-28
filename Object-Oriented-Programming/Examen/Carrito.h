//Carlos Ivan Armenta Naranjo A01643070
#ifndef CARRITO_H
#define CARRITO_H
#include "Producto.h"
#include "ProductoIVA.h"
#include "ProductoIVAIEPS.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Carrito{
    private:
        vector<Producto*> productos;
    public:
        void agregarProducto(Producto*c);
        double getSubtotalCuenta();
        double getImpuestosCuenta();
        double getTotalCuenta();

    friend ostream&operator<<(ostream& os,Carrito& car){
        os<<"Gracias por comprar con nosotros"<<endl<<"El sutotal sin impuestos es $"<<car.getSubtotalCuenta()<<endl<<"El total de impuestos a pagar es $"<<car.getImpuestosCuenta()<<endl<<"El total de su cuenta es $"<<car.getTotalCuenta();
        return os;
        }
};
#endif