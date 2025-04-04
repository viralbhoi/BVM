#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<float>> mat(3,vector<float> (4));
    for(int i=0;i<3;i++){
        cout<<"Enter coeff of x1 : ";
        cin>>mat[i][0];
        cout<<"Enter coeff of x2 : ";
        cin>>mat[i][1];
        cout<<"Enter coeff of x3 : ";
        cin>>mat[i][2];
        cout<<"Enetr D : ";
        cin>>mat[i][3];
    }
    int col = 0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(mat[i][col] != 0 || mat[i][col] != 1){
                float temp = 1.0 / mat[i][col];
                for(int k=0;k<4;k++){
                    mat[i][k] *= temp;
                }
            }else{
                if(mat[j][col] != 0){
                    float temp = mat[j][col];
                    for(int k=0;k<4;k++){
                        mat[j][k] -= temp * mat[i][k];
                    }
                }
            }
        }
        col++;
    }
    float x3 = mat[2][3];
    float x2 = mat[1][3] - mat[1][2]* x3;
    float x1 = mat[0][3] - mat[0][2] * x3 - mat[0][1] * x2;
    cout<<x1<<" "<<x2<<" "<<x3<<endl;
}