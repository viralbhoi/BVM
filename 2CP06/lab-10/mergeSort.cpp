#include<bits/stdc++.h>
using namespace std;

void merge (vector<int> &nums, int low, int mid, int high){
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while(left<=mid && right <= high){
        if(nums[left] < nums[right]){
            temp.push_back(nums[left++]);
        }else{
            temp.push_back(nums[right++]);
        }
    }

    while(left<=mid){
        temp.push_back(nums[left++]);
    }

    while(right <= high){
        temp.push_back(nums[right++]);
    }

    int j = 0;
    for(int i=low;i <= high;i++){
        nums[i] = temp[j++];
    }
}

void mergeSort(vector<int> &nums,int low, int high){
    if(low < high){ 
        int mid = (low + high) / 2;

        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
}

int main(){
    vector<int> nums = {121, 322, 306, -46, 92, 12, 90, 0, -7657, -89, 65748};

    mergeSort(nums,0,nums.size()-1);

    for(auto &it: nums){
        cout<<it<<" ";
    }
}