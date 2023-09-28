//Carlos Ivan Armenta Naranjo A01643070
#ifndef PRODUCTOIVAIEPS_H
#define PRODUCTOIVAIEPS_H
#include "ProductoIVA.h"
#include<iostream>
#include<string>
using namespace std;
class ProductoIVAIEPS:public ProductoIVA{
    private:
        int ml;
        const double IEPSxLT=1.5086;
        double getIEPS();
    public:
        ProductoIVAIEPS(int codigo, string descripcion, double precio, int cantidad,int ml);
        ProductoIVAIEPS(int codigo, string descripcion, double precio, int ml);
        double getImpuestos();
        double getTotal(); 
};
#endif