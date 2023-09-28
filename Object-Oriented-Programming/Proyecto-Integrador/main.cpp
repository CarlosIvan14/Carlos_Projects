//Autor Carlos Ivan Armenta Naranjo A01643070
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Videos.h"
#include "Capitulos.h"
#include "Peliculas.h"
using namespace std;

int main() {
    int op=7;
    vector<Videos*> contenidos;
    ifstream archivo("videos.txt");
    
    if (archivo.is_open()) {
        vector<string> lineas;
        string renglon;
        // Leer el archivo línea por línea y almacenar cada línea en el vector 'lineas'
        while (getline(archivo, renglon)) {
            lineas.push_back(renglon);
        }
        archivo.close();
        // Procesar cada línea del archivo
        for (int i = 0; i < lineas.size(); i++) {
            string tipo, id, nombre, duracion, genero, serie, episodio;
            stringstream ss(lineas[i]);
        // Analizar el tipo de video y crear un objeto de tipo pelicula o capitulos dependiendo del tipo
            getline(ss, tipo, ',');
            if (tipo == "p") {
                getline(ss, id, ',');
                getline(ss, nombre, ',');
                getline(ss, duracion, ',');
                getline(ss, genero, ',');
                int duracio = std::stoi(duracion);
                contenidos.push_back(new Peliculas(id, nombre, duracio, genero));
            } else if (tipo == "c") {
                getline(ss, id, ',');
                getline(ss, nombre, ',');
                getline(ss, duracion, ',');
                getline(ss, genero, ',');
                getline(ss, serie, ',');
                getline(ss, episodio, ',');
                int duracio = std::stoi(duracion);
                int cap = std::stoi(episodio);
                contenidos.push_back(new Capitulos (id, nombre, duracio, genero, serie, cap));
            } else {
                cout << "Error: El video no puede ser guardado ya que no está clasificado como Capítulo o Película." << endl;
                cout << "Verifica que tu formato siga los lineamientos establecidos por el programa." << endl;
            }
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }            
    int contenido=contenidos.size();
    //Menu interativo servicio de  streaming
    while (op!=9) {
        cout << "Elige por favor una de las siguiente opciones:" << endl;
        cout << "1) Mostrar catalogo con califficaciones" << endl;
        cout << "2) Calificar un video" << endl;
        cout << "3) Mostrar peliculas o capitulos con una calificacion minima determinada" << endl;
        cout << "4) Mostrar peliculas o capitulos de un cierto genero" << endl;
        cout << "9) Salir." << endl;
        cin >> op;

        if (op == 1) {
            cout<<"El catalogo completo de capitulos y peliculas disponibles es: "<<endl;
                for(int i=0;i<contenido;i++){
                    if(Peliculas*c=dynamic_cast<Peliculas*>(contenidos[i])){
                        cout<<*c<<endl;
                    }else if(Capitulos*c=dynamic_cast<Capitulos*>(contenidos[i])){
                        cout<<*c<<endl; 
                    }
                }
                continue;
        }else if (op==2){
            string id;
            int calificacion;
            cout<<"Dame el Id del video que deseas calificar: "<<endl;
            cin>>id;
            cout<<"Dame la calificiacion que deseas esta puede ser 1 , 2 , 3 , 4 o 5 : "<<endl;
            cin>>calificacion;
            if(calificacion>=1&&calificacion<=5){
                bool encontrado = false;
                for(int i=0;i<contenido;i++){
                    if(id==contenidos[i]->getId()){
                        contenidos[i]->calificarVideo(calificacion);
                        cout<<"Video calificado con exito"<<endl;
                        encontrado=true;
                    }
                }
                if(encontrado==false){
                    cout<<"El Id introducido no existe en la lista de videos, revisa nuestra lista e intentalo otra vez"<<endl;
                }
            }else{
                cout<<"La calificacion introducida no es valida, por favor introduce uan calificacion valida"<<endl;
            }
        } else if (op == 3) {
            int opcion;
            double calificacionMinima;
            cout<<"Introduce un numero entero para saber que es lo que quieres que te muestre:"<<endl;
            cout<<"Pelicula =1"<<endl;
            cout<<"Capitulo =2"<<endl;
            cout<<"Ambos =3"<<endl;
            cin>>opcion;
            if(opcion==1){
                cout<<"Dame la calificacion minima de 1 a 5(puedes introducir decimales), que tienen que tener las peliculas que quieres que muestre"<<endl;
                cin>>calificacionMinima;
                if(calificacionMinima>=0 && calificacionMinima<=5){
                    for(int i=0;i<contenido;i++){
                         if(Peliculas*c=dynamic_cast<Peliculas*>(contenidos[i])){
                            c->mostrarVideosCal(calificacionMinima);
                        } 
                    }
                }else{
                    cout<<"La calificacion introducida no esta dentro del rango"<<endl;
                }
            }else if(opcion==2){
                cout<<"Dame la calificacion minima de 1 a 5(puedes introducir decimales), que tienen que tener los capitulos que quieres que muestre"<<endl;
                cin>>calificacionMinima;
                if(calificacionMinima>=0 && calificacionMinima<=5){
                    for(int i=0;i<contenido;i++){
                         if(Capitulos*c=dynamic_cast<Capitulos*>(contenidos[i])){
                            c->mostrarVideosCal(calificacionMinima);
                        } 
                    }
                }else{
                    cout<<"La calificacion introducida no esta dentro del rango"<<endl;
                }
            }else if(opcion==3){
                cout<<"Dame la calificacion minima de 1 a 5(puedes introducir decimales), que tienen que tener las peliculas y capitulos que quieres que te muestre"<<endl;
                cin>>calificacionMinima;
                if(calificacionMinima>=0 && calificacionMinima<=5){
                    for(int i=0;i<contenido;i++){
                        contenidos[i]->mostrarVideosCal(calificacionMinima);
                    } 
                }else{
                    cout<<"La calificacion introducida no esta dentro del rango"<<endl;
                }
            }else{
                cout<<"Esa no es una opcion valida."<<endl;
            }
        } else if (op == 4) {
            int opcion;
            string genero;
            cout<<"Introduce un numero entero para saber que es lo que quieres que te muestre:"<<endl;
            cout<<"Pelicula =1"<<endl;
            cout<<"Capitulo =2"<<endl;
            cout<<"Ambos =3"<<endl;
            cin>>opcion;
            if(opcion==1){
                cout<<"Dame el genero que tienen que tener las peliculas que quieres que muestre (drama,accion o misterio)"<<endl;
                cin>>genero;
                if(genero=="accion"||genero=="drama"||genero=="misterio"){
                    for(int i=0;i<contenido;i++){
                         if(Peliculas*c=dynamic_cast<Peliculas*>(contenidos[i])){
                            c->mostrarVideosGen(genero);
                        } 
                    }
                }else{
                    cout<<"El genero introducido no es valido, recuerda que los tipos de genero son drama, accion o misterio"<<endl;
                }
            }else if(opcion==2){
                cout<<"Dame el genero que tienen que tener los capitulos que quieres que muestre (drama,accion o misterio)"<<endl;
                cin>>genero;
                if(genero=="accion"||genero=="drama"||genero=="misterio"){
                    for(int i=0;i<contenido;i++){
                         if(Capitulos*c=dynamic_cast<Capitulos*>(contenidos[i])){
                            c->mostrarVideosGen(genero);
                        } 
                    }
                }else{
                    cout<<"El genero introducido no es valido, recuerda que los tipos de genero son drama, accion o misterio"<<endl;
                }
            }else if(opcion==3){
                cout<<"Dame el genero que tienen que tener las peliculas y capitulos que quieres que te muestre (drama,accion o misterio)"<<endl;
                cin>>genero;
                 if(genero=="accion"||genero=="drama"||genero=="misterio"){
                    for(int i=0;i<contenido;i++){
                        contenidos[i]->mostrarVideosGen(genero);
                    } 
                }else{
                    cout<<"El genero introducido no es valido, recuerda que los tipos de genero son drama, accion o misterio"<<endl;
                }
            }else{
                cout<<"Esa no es una opcion valida."<<endl;
            }
        } else if(op==9){
                break;
        }else {
            cout<<"Esa no es una opcion valida."<<endl;
        }
    }
} 