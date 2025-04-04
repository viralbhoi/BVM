#include <bits/stdc++.h>
using namespace std;

void redixSort(vector<int> &nums)
{
    int maxi = *max_element(nums.begin(), nums.end());
    int mini = *min_element(nums.begin(), nums.end());

    int offset = mini < 0 ? -mini : 0;

    for (auto &it : nums)
    {
        it += offset;
    }

    int max_digit = ceil(log10(maxi));
    int n = nums.size();
    int div = 1;
    for (int k = 0; k < max_digit; k++)
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            int num = (nums[i] / div) % 10;
            mp[num].push_back(nums[i]);
        }

        div = div * 10;
        int j = 0;
        for (auto &p : mp)
        {
            // sort(p.second.begin(), p.second.end());

            for (auto it : p.second)
            {
                nums[j++] = it;
            }
        }
    }

    for (auto &it : nums)
    {
        it -= offset;
    }
}

int main()
{
    vector<int> nums = {92, 12, 11, 91, 92, 0, 14, 15, 42, 21, 10};

    redixSort(nums);

    for (auto it : nums)
    {
        cout << it << " ";
    }

    cout << endl;
}