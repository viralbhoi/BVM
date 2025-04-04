#include <bits/stdc++.h>
using namespace std;

const vector<int> spans = {4,2,1};

void shellSort(vector<int> &nums)
{
    int n = nums.size();
    for (auto span: spans)
    {
        // int span = spans[k];
        for (int i = span; i < n; i++)
        {
            int y = nums[i];
            int j = i - span;

            while (j >= 0 && y < nums[j])
            {
                nums[j + span] = nums[j];
                j -= span;

            }
            nums[j + span] =y;
        }
    }
}

int main()
{
    vector<int> nums = {9,8,-9999,6,5,4,3,-123456,1};

    shellSort(nums);

    for (auto it : nums)
    {
        cout << it << " ";
    }

    cout << endl;
}