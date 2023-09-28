//Autor Carlos Ivan Armenta Naranjo A01643070
#include "Capitulos.h"
Capitulos::Capitulos(string id, string titulo,int duracion,string genero,string serie, int episodio):Videos(id,titulo,duracion,genero){
    this->serie=serie;
    this->episodio=episodio;
}
Capitulos::Capitulos():Capitulos(" "," ",0," "," ",0){}
void Capitulos::mostrarVideosCal(double cal){
    if(promedio>=cal){
        if (this->promedio>0){
            cout<<this->id<<","<<this->titulo<<","<<this->promedio<<endl;
        }else{
            cout<<this->id<<","<<this->titulo<<","<<"SC"<<endl;
        }
    }
}
void Capitulos::mostrarVideosGen(string gen){
  if(genero==gen){
       if (this->promedio>0){
            cout<<this->id<<","<<this->titulo<<","<<this->genero<<","<<this->promedio<<endl;
        }else{
            cout<<this->id<<","<<this->titulo<<","<<this->genero<<","<<"SC"<<endl;
        }
    }
} 
