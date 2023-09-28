//Autor Carlos Ivan Armenta Naranjo A01643070
#ifndef PELICULAS_H
#define PELICULAS_H
#include "Videos.h"
#include<iostream>
#include<string>
using namespace std;
class Peliculas:public Videos{
    public:
        Peliculas();
        Peliculas(string id, string titulo,int duracion,string genero);
        void mostrarVideosCal(double cal);
        void mostrarVideosGen(string gen);
        friend  ostream&operator<<(ostream& os,Peliculas& pel){
        os<<pel.id<<","<<pel.titulo<<","<<pel.duracion<<","<<pel.genero<<",";
        if(pel.promedio>0){
            os<<pel.promedio;
        }else{
            os<<"SC";
        }
        return os;
}
};
#endif 