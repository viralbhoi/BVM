#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter string you want : ";
    cin>>n;

    unordered_set<string> st;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.insert(s);
    }

    int q;
    cout<<"Enter no. of queries: ";
    cin>>q;

    while(q--){
        string temp;
        cout<<"Enter query:";
        cin>>temp;

        if(st.find(temp) != st.end()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

