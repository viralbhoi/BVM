#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<float>> mat(3,vector<float> (3));

    for(int i=0;i<3;i++){
        cout<<"Enter coeff of x1 : ";
        cin>>mat[i][0];
        cout<<"Enter coeff of x2 : ";
        cin>>mat[i][1];
        cout<<"Enter coeff of x3 : ";
        cin>>mat[i][2];
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mat[i][i] != 0 || mat[i][i] != 1){
                float temp = 1.0 / mat[i][i];
                for(int k=0;k<4;k++){
                    mat[i][k] *= temp;
                }
            }
            float temp = 1.0 / mat[i][i];
            for(int k=0;k<3 && j!=i;k++){
                mat[j][k] -= temp * mat[i][k];
            }
            
        }
    }


    for(auto & itt : mat){
        for(auto& it: itt){
            cout<<it<<" ";
        }cout<<endl;
    }


}