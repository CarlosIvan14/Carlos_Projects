//Autor Carlos Ivan Armenta Naranjo A01643070
#include "Videos.h"
Videos::Videos(string id, string titulo,int duracion,string genero){
    this->id=id;
    this->titulo=titulo;
    this->duracion=duracion;
    this->genero=genero;
    this->promedio=0;
    this->cont=0;
}
Videos::Videos():Videos(" "," ",0," "){}
void Videos::calificarVideo(int cal){
    double calificacionAnterior= promedio*cont;
    promedio= (static_cast<double>(cal)+calificacionAnterior)/(cont+1);
    this->cont=cont+1;
}
string Videos::getId(){
    return this->id;
}