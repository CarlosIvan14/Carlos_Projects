#include <iostream>
using namespace std;
#define SIZE 10
class Stack {
    //Properties
    int *arr;
    int top;
    int capacity;
    //Methods
    public:
        Stack(int size);
        void push(int);
        int pop();
        int peak();
        int size();
        bool isEmpty();
        bool isFull();
};
//Definition of methods
Stack::Stack(int size){
    size=SIZE;
    this->arr=new int[size];
    this->capacity=0;
    this->top=-1;
}
void Stack::push(int num ){
    if(isFull()){
        cout<<"El arreglo esta lleno actualmente, no se pueden agregar mas elementos"<<endl;
    }else{
        this->top=num;
        arr[capacity+1]=num;
        capacity++;
    }
}
int Stack::pop(){
    if(isEmpty()){
        cout<<"El arreglo estsa vacio actualmente y no se pueden eliminar elementos"<<endl;
        return 0;
    }else{
        int num=arr[capacity];
        arr[capacity]=-1;
        top=arr[capacity-1];
        capacity--;
        return num;
    }
}
int Stack::peak(){
    if(isEmpty()){
        cout<<"El arreglo esta vacio actualmente por lo que no se puede encontrar el peak"<<endl;
        return -1;
    }else{
        return top;
    }
}
int Stack::size(){
    return capacity;
}
bool Stack::isEmpty(){
    return (top==0&&capacity==0);
}
bool Stack::isFull(){
    return(capacity==10);
}
int main(){
    Stack stak(10);
    cout<<"Vacio "<<stak.isEmpty()<<endl;
    stak.push(10);
    stak.push(20);
    stak.push(30);
    stak.push(40);
    stak.push(50);
    stak.push(60);
    stak.push(70);
    stak.push(80);
    stak.push(90);
    stak.push(100);
    stak.push(110);

    cout<<stak.pop()<<endl;
    cout<<stak.pop()<<endl;
    cout<<stak.pop()<<endl;

    cout<<"Peak: "<<stak.peak()<<endl;
    cout<<"Size: "<<stak.size()<<endl;
    stak.push(110);
    stak.push(120);
    cout<<"Peak: "<<stak.peak()<<endl;
    cout<<"Size: "<<stak.size()<<endl;
    cout<<"Vacio "<<stak.isEmpty()<<endl;
    stak.push(130);
    cout<<"Lleno "<<stak.isFull()<<endl;
    return 0;
}