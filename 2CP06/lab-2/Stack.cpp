#include<bits/stdc++.h>
using namespace std;

template <class T>
class Stack{
    T a[1000];
    int tos;

public:
    Stack(){
        tos=-1;
    }
    void push (T val){
        try{
            if(tos==1000){
                throw 1;
            }
        }catch(int a){
            cout<<"Stack is full"<<endl;
            return;
        }

        a[++tos] = val;
    }

    T pop (){
        try{
            if(tos==-1){
                throw 1;
            }
        }catch(int a){
            cout<<"Stack is empty"<<endl;
            return -1e9;
        }
        return a[tos--];
    }

    bool empty(){
        return tos == -1;
    }

    T top(){
        return a[tos];
    }

    int size(){
        return tos+1;
    }
};

