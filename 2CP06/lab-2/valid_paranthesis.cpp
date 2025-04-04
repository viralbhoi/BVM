#include "Stack.h"
#include<bits/stdc++.h>
using namespace std;



unordered_map<char,int> mp = {{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};

bool valid_parenthesis(string &s){
    Stack<char> st;
    int n = s.size();
    int i=0;
    while(i<n){

        if(mp[s[i]]>0){
            st.push(s[i]);
        }else{
            if(st.empty()){
                return false;
            }
            char c = st.pop();

            if(mp[c]+mp[s[i]] != 0 ){
                return false;
            }
        }
        i++;
    }

    return st.empty()==true;
}

int main(){

    string s = "{([])()[[]]{[()]}}";
    if(valid_parenthesis(s)){
        cout<<s<<" is valid\n";
    }else{
        cout<<"Invalid\n";
    }
}


