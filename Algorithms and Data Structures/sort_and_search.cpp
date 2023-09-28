#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bubbleSort(vector<int>&vector){
    for(int i = 0; i<vector.size(); i++){
        for(int j = 0; j<((vector.size()-1)-i); j++){
            if(vector[j+1]<vector[j]){
            int aux = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = aux;
        }
        }
    }
}
void mergeSort(vector<int>&a,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        vector<int> res(high+1);
        int i=low;
        int j=mid+1;
        int k=0;
        while(i<=mid&&j<=high){
            if(a[i]<=a[j]){
                res[k]=a[i];
                i+=1;
            }else{
                res[k]=a[j];
                j+=1;
            }
            k+=1;
        }
        while(i<=mid){
            res[k]=a[i];
            i+=1;
            k+=1;
        }
        while(j<=high){
            res[k]=a[j];
            j+=1;
            k+=1;
        }
        for(int h=0;h<k;h++){
            a[low+h]=res[h];
        }
    }
}
int sequentialSearch(vector<int>a,int key){
    for(int i=0;i<=a.size();i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}
int recursiveBinarySearch(vector<int> a,int key,int low,int high){
    if(low<=high){
        int mid=low +(high-low)/2;
        if(a[mid]==key){
            return mid;
        }
        if(a[mid]<key){
             return recursiveBinarySearch(a,key,mid+1,high);
        }else{
             return recursiveBinarySearch(a,key,low,mid-1);
        }
        return recursiveBinarySearch(a,key,low,high);
    }else{
        return -1;
    }
}
int IterativeBinarySearch(vector<int> a,int key,int low,int high){
    while(low<=high){
        int mid=low +(high-low)/2;
        if(a[mid]==key){
            return mid;
        }
        if(a[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    vector <int>a = {2,1,5,4,3,6,7,8,9,11,11,10,14,15,16,17};
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    int zise= a.size();
    mergeSort(a,0,a.size()-1);
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Position of 2 in the vector: "<<sequentialSearch(a,2)<<endl;
    cout<<"Position of 32 in the vector: "<<IterativeBinarySearch(a,32,0,zise-1)<<endl;
    cout<<"Position of 17 in the vector: "<<recursiveBinarySearch(a,17,0,zise-1)<<endl;
    vector <int>a2 = {2,1,5,3,3,5,68,9,81,121,1,14,15,16,17};
    for(int i:a2){
        cout<<i<<" ";
    }
    cout<<endl;
    bubbleSort(a2);
    for(int i:a2){
        cout<<i<<" ";
    }
}