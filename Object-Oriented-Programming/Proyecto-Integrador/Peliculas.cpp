//Autor Carlos Ivan Armenta Naranjo A01643070
#include "Peliculas.h"
Peliculas::Peliculas(string id, string titulo,int duracion,string genero):Videos(id,titulo,duracion,genero){}
Peliculas::Peliculas():Videos(){}
void Peliculas::mostrarVideosCal(double cal){
    if(promedio>=cal){
        if (this->promedio>0){
            cout<<this->id<<","<<this->titulo<<","<<this->promedio<<endl;
        }else{
            cout<<this->id<<","<<this->titulo<<","<<"SC"<<endl;
        }
}
}
void Peliculas::mostrarVideosGen(string gen){
    if(genero==gen){
       if (this->promedio>0){
            cout<<this->id<<","<<this->titulo<<","<<this->genero<<","<<this->promedio<<endl;
        }else{
            cout<<this->id<<","<<this->titulo<<","<<this->genero<<","<<"SC"<<endl;
        }
    }
    
} 

