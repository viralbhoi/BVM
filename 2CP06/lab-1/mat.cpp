#include<bits/stdc++.h>
using namespace std;

unordered_map <int,string> day = {{0,"Monday"},{1,"Tuesday"},{2,"Wednesday"},{3,"Thursday"},{4,"Friday"},{5,"Saturday"},{6,"Sunday"}};

class Mat
{
    int city;
    unordered_map <int,string> city_name;
    vector<vector<int>> temprature;
public:
    Mat(int c = 0){
        city = c;
        for(int i=0;i<city;i++){
            string s;
            cout<<"Enter name of city "<< i + 1<<endl;
            cin>>s;
            city_name[i] = s;

            cout<<"Enter Temprature of city "<<city_name[i]<<" : ";
            vector<int> v(7);
            for(int i=0;i<7;i++){
                cout<<day[i]<<" : ";
                cin>>v[i];
            }

            temprature.push_back(v);
        }

    }

    void max_temprature (string &city_n,string &d,int &tem){
        int max_t = -1;
        int max_x=0,max_y=0;
        for(int i=0;i<city;i++){
            for(int j=0;j<7;j++){
                if(temprature[i][j] > max_t){
                    max_x = i;
                    max_y = j;
                    max_t = temprature[i][j];
                }
            }
        }

        city_n = city_name[max_x];
        d = day[max_y];
        tem = max_t;
    }

    void display(){
        for(int i=0;i<city;i++){
            for(int j=0;j<7;j++){
                cout <<"temp of " << city_name[i]<<" on "<<day[i]<<" : "<<temprature[i][j]<<endl;
            }
        }
    }
};

int main(){
    Mat m(3);
    m.display();
    string city;
    string day;
    int temp;
    m.max_temprature(city,day,temp);

    cout<<"MAX TEMP. is at "<<city <<" on "<<day<<" with temprature "<<temp<<endl;
}
