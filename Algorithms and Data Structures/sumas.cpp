#include <iostream>
#include <string>
using namespace std;
int sumaIterativa(int n){
    if(n>0){
        int suma=0;
        for(int i=1;i<=n;i++){
            suma=suma+i;
        }
        return suma;
    }else{
        return 0;
    }
}
int sumaRecursiva(int n,int cont){
    if(n>0){
        if(cont==n){
            return cont;
        }
        return cont+sumaRecursiva(n,cont+1);
    }else{
        return 0;
    }
}
int sumaDirecta(int n){
    if(n>0){
        int suma=n*(n+1)/2;
        return suma;
    }else{
        return 0;
    }
}
int main(){
    int n;
    cout<<"Dame el numero hasta el cual deseas conocer la suma : ";
    cin>>n;
    cout<<"Suma Iterativa hasta "<<n<<" : "<<sumaIterativa(n)<<endl;
    cout<<"Suma Recursiva hasta "<<n<<" : "<<sumaRecursiva(n,1)<<endl;
    cout<<"Suma Directa hasta "<<n<<" : "<<sumaDirecta(n)<<endl;
}