#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int min_idx = -1;
        for (int j = i+1; j < n; j++)
        {
            if(nums[j]<nums[i]){
                // if(min_idx == -1){
                    min_idx = j;
                // }
                // else if(nums[j] < nums[min_idx]){
                //     min_idx = j;
                // }
                
            }
        }

        if (min_idx != -1)
        {
            swap(nums[i],nums[min_idx]);
        }
    }
}

int main()
{
    vector<int> nums = {9999999,-1, -2, -3,-1, -100, -500, -999, 0, 0, 0, 11111, 283469470, -867462558};

    selectionSort(nums);

    for (auto it : nums)
    {
        cout << it << " ";
    }

    cout << endl;
}