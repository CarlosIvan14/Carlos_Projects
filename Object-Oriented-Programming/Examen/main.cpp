#include "Carrito.h"
int main(){
    Carrito carrito;
    carrito.agregarProducto(new Producto(1,"Tortilla",15.5));
    carrito.agregarProducto(new Producto(2,"Bolillo",8,5));
    carrito.agregarProducto(new ProductoIVA(3,"Detergente",40));
    carrito.agregarProducto(new ProductoIVA(4,"Queso",50,4));
    carrito.agregarProducto(new ProductoIVAIEPS(5,"Refresco",60,1500));
    carrito.agregarProducto(new ProductoIVAIEPS(6,"Bebida energetica",50,5,250));
    cout<<carrito<<endl;
    return 0;
}