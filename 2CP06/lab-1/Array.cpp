#include<iostream>
using namespace std;

const int max_size = 1000;

void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

class Array{
    int *a;
    int n;
public:
    Array(int x = 100){
        n=x;
        a = new int[max_size];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
    }

    ~Array(){
        delete []a;
    }

    void sort (){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]>a[j]){
                    swap(a[i],a[j]);
                }
            }
        }
    }

    void display(){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    void delete_ele (int idx){
        for(int i=idx;i<n-1;i++){
            a[i] = a[i+1];
        }
        n--;
    }

    void insert(int idx,int val){
        for(int i=n-1;i>=idx;i--){
            a[i+1] = a[i];
        }

        a[idx] = val;
        n++;
    }

    void insert(int val){
        int i = n;
        for(i=n-1;i>=0;i--){

            if(a[i] < val){
                break;
            }
            a[i+1] = a[i];
        }


        a[i+1] = val;
        n++;
    }
};

int main()
{
    Array a(5);
    a.display();
    a.delete_ele(2);
    a.display();
    a.sort();
    a.display();
    a.insert(1,5);
    a.display();
    a.sort();
    a.display();
    a.insert(-1);
    a.display();
}
