#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,11,-22,-35};
    int target = 7;
    int x=-1;
    int y=-1;
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        for(int j=i=1;j<n;j++){
            if(nums[i]+nums[j] == target){
                x=i;
                y=j;
                break;
            }
        }
    }

    cout<<x<<" "<<y<<endl;


    cout<<endl;
}

