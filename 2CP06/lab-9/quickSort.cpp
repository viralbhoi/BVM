#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r)
{
    // cout<<"inside Partition"<<endl;
    int pivot = l;
    int down = l;
    int up = r;
    while (down < up)
    {
        while (down < r && arr[down] <= arr[pivot])
        {
            down++;
        }

        while (up >= l +1 && arr[up] > arr[pivot])
        {
            up--;
        }
        if(down<up)
            swap(arr[down], arr[up]);
    }

    swap(arr[pivot], arr[up]);
    return up;
}

void qs(vector<int> &arr, int l, int r)
{
    // cout<<"inside qs funtion"<<endl;
    if(l<r){
        int pivot = partition(arr,l,r);
        qs(arr,l,pivot-1);
        qs(arr,pivot+1,r);
    }
}

void quickSort(vector<int> &arr)
{
    // cout<<"Inside quickSort" << endl;
    qs(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> nums = {-1,-2,-3,-100,-500,-999,0,0,0,11111,283469470, -867462558};
    quickSort(nums);

    for(auto it: nums){
        cout<<it<<" ";
    }
}