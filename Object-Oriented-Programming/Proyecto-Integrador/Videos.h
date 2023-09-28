//Autor Carlos Ivan Armenta Naranjo A01643070
#ifndef VIDEOS_H
#define VIDEOS_H
#include<iostream>
#include<string>
using namespace std;
class Videos
{
protected:
    string id;
    string titulo;
    int duracion;
    string genero;
    double promedio;
    int cont;
public:
    Videos();
    Videos(string id, string titulo,int duracion,string genero);
    virtual void mostrarVideosCal(double calMin)=0;
    virtual void mostrarVideosGen(string gen)=0;
    void calificarVideo(int cal);
    string getId();
};
#endif 


