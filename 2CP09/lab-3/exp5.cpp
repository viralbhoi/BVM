#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<int> st;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        st.insert(x);
        v.push_back(x);
    }

    int mex = 0;

    while (st.find(mex) != st.end() && count(v.begin(),v.end(),mex))
    {
        mex++;
    }

    cout << "Smallest missing integer is : " << mex << endl;
}
