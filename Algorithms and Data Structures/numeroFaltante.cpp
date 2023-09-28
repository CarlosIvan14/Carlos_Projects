#include <iostream>
using namespace std;
int sumaDirecta(int n){
    if(n>0){
        int suma=n*(n+1)/2;
        return suma;
    }else{
        return 0;
    }
}
int encutran_Num(int arr[],int size){
 int sumaTeorica=0;
 int sumaReal=0;
sumaTeorica=sumaDirecta(size+1);

 for(int i=0; i<=size;i++){
    sumaReal= arr[i]+sumaReal;
 }
 int num=0;
 return(num=sumaTeorica-sumaReal);
}

int main(){
    int a []={1,3,4,5,6};
     int size = sizeof(a) / sizeof(a[0]);
     
    cout<<"Numero Faltante: "<<encutran_Num(a,size)<<endl;
    return 0;
}