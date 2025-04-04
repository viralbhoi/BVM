#include<bits/stdc++.h>
using namespace std;
struct myComp
{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.second<b.second;
    }
};

int main()
{
    /* priority_queue<int> pq;

     int n;
     cout<<"Enter elements : ";
     cin>>n;

     for(int i=0;i<n;i++){
         int x;
         cin>>x;
         pq.push(x);
     }

     while(!pq.empty()){
         cout<<pq.top()<<endl;
         pq.pop();
     }

     priority_queue<int,vector<int>,greater<int>> asc_pq;

     cout<<"Enter elements : ";
     cin>>n;

     for(int i=0;i<n;i++){
         int x;
         cin>>x;
         asc_pq.push(x);
     }

     while(!asc_pq.empty()){
         cout<<asc_pq.top()<<endl;
         asc_pq.pop();
     } */

    priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> spq;

    spq.push({1,3});
    spq.push({1,2});
    spq.push({100,5});
    spq.push({12,1});
    spq.push({13,4});
    spq.push({10,6});

    while(!spq.empty())
    {
        cout<<spq.top().first<<" "<<spq.top().second<<endl;
        spq.pop();
    }
}
