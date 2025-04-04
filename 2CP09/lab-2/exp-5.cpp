#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    unordered_map<string,int> mp;
    while(q--){
        cout<<"Enter query :";
        int x;
        cin>>x;

        if(x==1){
            string n;
            int y;
            cin>>n>>y;

            mp[n] += y;
        }else if(x==2){
            string n;
            cin>>n;
            if(mp.find(n) != mp.end()){
                mp.erase(n);
            }
        }else if(x==3){
            string n;
            cin>>n;
            cout<<n<<" "<<mp[n]<<endl;
        }else{
            cout<<"Invalid\n\n";
        }
    }
}

