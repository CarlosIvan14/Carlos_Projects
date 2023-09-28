//Carlos Ivan Armenta Naranjo A01643070
#include "Carrito.h"
void Carrito::agregarProducto(Producto*c){
    productos.push_back(c);
}
double Carrito::getSubtotalCuenta(){
    double subTotalCuenta=0;
    for(int i=0;i<productos.size();i++){
        if(Producto*c=dynamic_cast<Producto*>(productos[i])){
            subTotalCuenta=c->getSubtotal()+subTotalCuenta;
        }else if(ProductoIVA*c=dynamic_cast<ProductoIVA*>(productos[i])){
            subTotalCuenta=c->getSubtotal()+subTotalCuenta;
        }else if(ProductoIVAIEPS*c=dynamic_cast<ProductoIVAIEPS*>(productos[i])){
            subTotalCuenta=c->getSubtotal()+subTotalCuenta;
        }
    }
    return subTotalCuenta;
}
double Carrito::getImpuestosCuenta(){
    double impuestosCuenta=0;
    for(int i=0;i<productos.size();i++){
        if(Producto*c=dynamic_cast<Producto*>(productos[i])){
            impuestosCuenta=c->getImpuestos()+impuestosCuenta;
        }else if(ProductoIVA*c=dynamic_cast<ProductoIVA*>(productos[i])){
            impuestosCuenta=c->getImpuestos()+impuestosCuenta;
        }else if(ProductoIVAIEPS*c=dynamic_cast<ProductoIVAIEPS*>(productos[i])){
            impuestosCuenta=c->getImpuestos()+impuestosCuenta;
        }
    }
    return impuestosCuenta;
}
double Carrito::getTotalCuenta(){
    double totalCuenta=0;
    for(int i=0;i<productos.size();i++){
        if(Producto*c=dynamic_cast<Producto*>(productos[i])){
            totalCuenta=productos[i]->getTotal()+totalCuenta;
        }else if(ProductoIVA*c=dynamic_cast<ProductoIVA*>(productos[i])){
            totalCuenta=productos[i]->getTotal()+totalCuenta;
        }else if(ProductoIVAIEPS*c=dynamic_cast<ProductoIVAIEPS*>(productos[i])){
            totalCuenta=productos[i]->getTotal()+totalCuenta;
        }
    }
    return totalCuenta;
}