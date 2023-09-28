
#include <iostream>
#include <string>
using namespace std;
void insertion_Sort(int A[], int N){
    int j,key,i;
    for (j=1;j<N;j++){
         key=A[j];
         i= j-1;
         while(i>=0 && A[i]>key){
            A[i+1]=A[i];
            i=i-1;
         }
         A[i+1]=key;
    }
}
int main(){
    int miVector[]={4,3,1,5,7,2,9,8,0,-1,-3,5};
    cout<<"Tu vector sin ordenar es: ";
    for(int i:miVector){
        cout<<i<<" ";
    }
    cout<<endl;
    int N=sizeof(miVector)/sizeof(miVector[0]);
    insertion_Sort(miVector,N);
    cout<<"Tu vector ordenado es: ";
    for(int h:miVector){
        cout<<h<<" ";
    }
}