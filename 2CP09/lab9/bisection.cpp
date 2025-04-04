#include<bits/stdc++.h>
using namespace std;

float f (float x){
    return (x*x*x + 1000);
}

const int max_itr = 10;
int itr = 0;

int main(){
    float a = -11;
    float b = 11;
    float e = 0.1;

    if(f(a) * f(b) > 0){
        cout<<"Wrong guess"<<endl;
        return 1;
    }
    while(itr < max_itr){
        float c  = (a + b)/2;
        

        if(f(c) == 0){
            cout<<f(c)<<endl;
        }
        if(abs((a - b) / c) < e){
            cout<< c <<endl;
            break;
        }

        

        if((f(c) * f(a)) > 0){
            a = c;
        }else{
            b = c;
        }
        itr++;
    }

    if(itr==max_itr){
        cout<<"No roots"<<endl;
    }


}