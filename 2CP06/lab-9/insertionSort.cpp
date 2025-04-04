#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j <n; j++)
        {
            if(nums[i]> nums[j]){
                swap(nums[i],nums[j]);
            }
        }
    }
}

int main(){
    vector<int> nums = {-1, -2, -3, -100, -500, -999, 0, 0, 0, 11111, 283469470, -867462558};

    insertionSort(nums);

    for (auto it : nums)
    {
        cout << it << " ";
    }

    cout << endl;
}