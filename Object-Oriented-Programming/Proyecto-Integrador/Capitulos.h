//Autor Carlos Ivan Armenta Naranjo A01643070
#ifndef CAPITULOS_H
#define CAPITULOS_H
#include<iostream>
#include<string>
#include "Videos.h"
using namespace std;
class Capitulos:public Videos{
private:
    string serie;
    int episodio;
public:
    Capitulos();
    Capitulos(string id, string titulo,int duracion,string genero,string serie, int episodio);
    void mostrarVideosCal(double cal);
    void mostrarVideosGen(string gen);
    friend  ostream&operator<<(ostream& os,Capitulos& cap){
        os<<cap.id<<","<<cap.titulo<<","<<cap.duracion<<","<<cap.genero<<","<<cap.serie<<","<<cap.episodio<<",";
        if(cap.promedio>0){
            os<<cap.promedio;
        }else{
            os<<"SC";
        }
        return os;
}
};
#endif 