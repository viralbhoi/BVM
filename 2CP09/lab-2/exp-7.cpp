#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> mp;

    int n;
    cout<<"How many input you want to enter \n";
    cin>>n;

    for (int i=0;i<n;i++){
        string s;
        cin>>s;

        mp[s]++;
    }

    for(auto a : mp){
        cout<<"Key: "<<a.first<<" freq. : "<<a.second<<endl;
    }
}
