#include <iostream>
#include <string>
using namespace std;
int main(){
    cout<<"Ejercicio 5"<<endl;
    double num,factorial;
    cout<<"Factorial de un numero"<<endl;
    cout<<"Introduce el numero del cual quieres conocer su factorial"<<endl;
    cin>>num;
    if(num==0){
        factorial=1;
    }else{
        factorial=1;
        for(int i=1;i<=num;i++){
            factorial=i*factorial;
        }
    }
    cout<<"El factorial de "<<num<<" es: "<<factorial<<endl;
}