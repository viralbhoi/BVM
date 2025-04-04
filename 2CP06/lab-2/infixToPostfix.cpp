#include "Stack.h"
#include<bits/stdc++.h>
using namespace std;

int evaluate(int a,int b,char op){
    if(op=='+'){
        return a+b;
    }else if(op=='-'){
        return a-b;
    }else if(op=='*'){
        return a*b;
    }else if(op=='/'){
        return a/b;
    }else if(op=='^'){
        return pow(a,b);
    }
}


int postEvaluation(string &exp){
    Stack<int> st;

    int i=0;

    while(i<exp.size()){
        if(exp[i]>='0' && exp[i]<='9'){
            st.push(exp[i]-'0');
        }else{
            int b = st.pop();
            int a = st.pop();

            st.push(evaluate(a,b,exp[i]));
        }
        i++;
    }


    return st.pop();
}


int main(){
    string e = "123*+5+";
    cout<<postEvaluation(e)<<endl;
    e = "13+623^6*++";
    cout<<postEvaluation(e)<<endl;
}
