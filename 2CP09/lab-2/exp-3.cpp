#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,1,1,2,2,2,3,4,5,6,6,7,8,9,10,10};
    int m = nums.size();
    for(int i=0;i<m-1;i++){
        if(nums[i]==nums[i+1]){
            nums.erase(nums.begin()+i+1);
            m--;
            i--;
        }
    }

    for(auto n:nums){
        cout<<n<<" ";
    }
    cout<<endl;
}
