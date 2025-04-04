#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, -20, 3, 4, 5, 6, 7, 8, 9, 11, -22, -35};
    int target = 7;
    int x = -1;
    int y = -1;
    int n = nums.size();

    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                x = i;
                y = j;
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    if (x == -1 && y == -1)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << x << " " << y << endl;
    }

    cout << endl;

    // o nlog n soln 

    unordered_map<int,int> mp;

    for(int i = 0;i<n;i++){
        mp [nums[i]] = i;
    }

    int l=0,r=n-1;
    sort(nums.begin(),nums.end());
    while(l<r){
        int sum = nums[l]+nums[r];
        if(sum == target){
            break;
        }else if(sum > target){
            r--;
        }else{
            l++;
        }
    }

    cout<<mp[nums[l]] <<" "<<mp[nums[r]]<<endl;

    // O n

    // mp.clear();
    // for(int i=0;i<n;i++){
    //     if(mp.find(target-nums[i]) != mp.end()){
    //         cout<<i <<" "<<mp[target-nums[i]];
    //         break;
    //     }
    //     mp[nums[i]] = i;
    // }
}
