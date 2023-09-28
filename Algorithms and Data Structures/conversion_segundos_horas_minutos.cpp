#include <iostream>
#include <string>
using namespace std;
int main(){
    cout<<"Ejercicio 4"<<endl;
    int seg,h, m, segr;
    cout<<"Segundos a horas, minutos y segundos"<<endl;
    cout<<"Introduce una cantidad de segundos" <<endl;
    cin>>seg;
    h=seg/3600;
    segr=seg%3600;
    m=segr/60;
    segr=segr%60;
    cout<<seg<<" segundos en horas, minutos y segundos son: "<<h<<" horas, "<<m<<" minutos, "<<segr<<" segundos"<<endl;
    
}