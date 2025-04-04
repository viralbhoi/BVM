#include <bits/stdc++.h>
using namespace std;

bool comp (const vector<int> &a, const vector<int> &b){
    float l = 1.0*a[0]/a[1];
    float m = 1.0*b[0]/b[1];

    return (l<m);
}

int main(){
    vector<vector<int>> v;

    int n;
    cout<<"Enter The size : ";
    cin>>n;

    for(int i=0;i<n;i++){
        int val;
        int wieght;

        cout<<"Enter val & wieght"<<endl;
        cin>>val>>wieght;

        v.push_back({val,wieght});
    }

    sort(v.begin(),v.end(),comp);
    cout<<"Sorted by ratio\n\n";
    for(auto it : v){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
}
