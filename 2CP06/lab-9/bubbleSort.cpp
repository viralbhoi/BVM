#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        bool swp = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j+1], nums[j]);
                swp = true;
            }
        }

        if (!swp)
        {
            break;
        }
    }
}

int main()
{
    vector<int> nums = {-1, -2, -3, -100, -500, -999, 0, 0, 0, 11111, 283469470, -867462558};

    bubbleSort(nums);

    for (auto it : nums)
    {
        cout << it << " ";
    }

    cout << endl;
}