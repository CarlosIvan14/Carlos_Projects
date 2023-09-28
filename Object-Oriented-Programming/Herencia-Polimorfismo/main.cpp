#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Hotel.h"

int main() {
    Hotel* hotel;
    int op = 9;

    while (op != 7) {
        cout << "Elige por favor una de las siguiente opciones:" << endl;
        cout << "1) Crear Hotel" << endl;
        cout << "2) Hacer check-in" << endl;
        cout << "3) Hacer check-out" << endl;
        cout << "4) Realizar cargos a habitacion." << endl;
        cout << "5) Ingresos por tarifas." << endl;
        cout << "6) Generar reporte por ocupacion." << endl;
        cout << "7) Salir." << endl;
        cin >> op;

        if (op == 1) {
            string nombre;
            int numJunior;
            int numSuite;
            int numDeluxe;

            cout << "Dame el nombre del Hotel" << endl;
            cin >> nombre;
            cout << "Dame el numero de habitaciones Junior para este hotel: " << endl;
            cin >> numJunior;
            cout << "Dame el numero de habitaciones Suite para este hotel: " << endl;
            cin >> numSuite;
            cout << "Dame el numero de habitaciones Deluxe para este hotel: " << endl;
            cin >> numDeluxe;

            hotel= new Hotel(nombre, numJunior, numSuite, numDeluxe);
            

            cout << "Hotel creado con exito" << endl;
        }else if (op==2){
            int tipoHabitacion;
            string nombre;
            int adultos;
            int infantes;
            int credito;
            cout<<"Dame el nombre del nuevo huesped"<<endl;
            cin>>nombre;
            cout<<"Dame el numero de adultos que se alojaran en la habitacion"<<endl;
            cin>>adultos;
            cout<<"Dame el numero de infantes que se alojaran en la habitacion"<<endl;
            cin>>infantes;
            cout<<"Dime cuanto credio dejaras desponible para esta habitacion"<<endl;
            cin>>credito;
            cout<<"Escriba el tipo de Habitacion deseada (1=Junior, 2=Suit y 3 = Deluxe)"<<endl;
            cin>>tipoHabitacion;
            int numHabitacional=hotel->checkin(nombre,adultos,infantes,credito,tipoHabitacion);
            if(numHabitacional>-1){
                cout<<"Tu checkin esta listo, estas alojado en la habitacion numero: "<<numHabitacional<<endl;
                cout<<endl;
            }else if(numHabitacional==-2){
                cout<<"Tu checkin no se pudo realizar ya que el numero de personas excede a la capacidad del tipo que seleccionaste el cual fue:"<<tipoHabitacion;
                if(tipoHabitacion==1){
                    cout<<" Junior"<<endl;
                }else if(tipoHabitacion==2){
                    cout<<" Suite"<<endl;
                }else if(tipoHabitacion==3){
                    cout<<" Deluxe"<<endl;
                }
                cout<<"Selecciona otro por favor y vuelve a intentarlo."<<endl;
                cout<<endl;
            }else if(numHabitacional==-3){
                cout<<"Tu checkin no se pudo realizar ya que el numero de personas excede a la capacidad de la habitacion Deluxe."<<endl;
                cout<<"Por favor realiza reservaciones separadas"<<endl;
                cout<<endl;
            }
            else{
                cout<<"Tu checkin no se pudo realizar"<<endl;
                cout<<endl;
            }
            } 
        else if (op == 3) {
            int num;
            bool exito;

            cout << "Dame el numero de la habitacion que deseas liberar" << endl;
            cin >> num;
            exito = hotel->checkout(num);

            if (exito == true) {
                cout << "Check out listo y realizado con exito" << endl;
                cout<<endl;
            } else {
                cout << "No se pudo realizar el check out" << endl;
                cout<<endl;
            }
        } else if (op == 4) {
            int num;
            double monto;
            bool cargoRealizado;

            cout << "Dame el numero de la habitacion a la que deseas realizar un cago" << endl;
            cin >> num;
            cout << "Dame el monto del cargo" << endl;
            cin >> monto;

            cargoRealizado = hotel->realizarCargosHabitacion(num, monto);

            if (cargoRealizado == true) {
                cout << "Cargo realizado con exito" << endl;
                cout<<endl;
            } else {
                cout << "No se pudo realizar el cargo" << endl;
                cout<<endl;
            }
        } else if (op == 5) {
            double total = hotel->getTotalXTarifaBase();
            cout << "El total por tarifa base es: " << total << endl;
            cout<<endl;
        } else if (op == 6) {
            hotel->imprimeOcupacion();
            cout<<endl;
        }
    }
}


