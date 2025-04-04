#include<bits/stdc++.h>
#include<fstream>

using namespace std;

class Student{
    string id;
    float marks;

public:

    friend istream& operator>> (istream& i,Student &s){
        i>>s.id>>s.marks;
        return i;
    }

    friend ostream& operator<< (ostream& o,Student &s){
        o<<s.id<<s.marks;
        return o;
    }

    friend float average(vector<Student> st){
        float sum = 0;

        for(auto std : st){
            sum += std.marks;
        }

        float avg = sum/st.size();
        return avg;
    }

    friend float standard_devition(vector<Student> st){
        float varience = 0;
        float avg = average(st);

        for(auto std: st){
            float temp = std.marks - avg;
            varience += temp * temp;
        }

        float sd = sqrt((varience/st.size()));

        return sd;
    }

    void display(){
        cout<<"Id : "<<id<<endl<<"Marks : "<<marks<<endl;
    }

    float getMarks()
    {
        return marks;
    }

    string getId(){
        return id;
    }
    
};

bool comp(Student &s1,Student &s2) {
    float a = s1.getMarks();
    float b = s2.getMarks();
    return a>b;
}

int main()
{
    Student s;
    vector<Student> st;

    fstream fl;
    fl.open("inp.txt" ,ios::in | ios::out);
   

    while(fl){
        fl>>s;
        if(fl)
            st.push_back(s);
    }

    for(auto std:st){
        std.display();
    }
    cout<<"\n\nafter sorting\n\n";
    sort(st.begin(),st.end(),comp);

    for(auto stf:st){
        stf.display();
    }

    cout<<"\n\nAverage : "<<average(st)<<endl;
    cout<<"SD : "<<standard_devition(st)<<endl<<endl;
    
    string id;
    cout<<"Enter id Where you want to change Marks : ";
    cin>>id;


    bool find = false;
    fl.clear();
    fl.seekg(0,ios::beg);
    int cur = fl.tellg();
    while(fl && !find){
        fl>>s;

        if(s.getId() == id){
            cout<<"Id Found, please enter new marks :";
            float nMark;
            cin>>nMark;

            fl.seekp(cur,ios::beg);
            fl<<id<<" "<<nMark<<endl;
            find = true;
            break;
        }
        cur = fl.tellg();
    }

    if(!find){
        cout<<"Id Not Found!"<<endl;
    }
    fl.clear();
    fl.seekg(0,ios::end);
    fl.seekp(0,ios::end);
    int mar;
    cout<<"Enter if and marks you want to enter";
    cin>>id>>mar;
    fl<<id<<" "<<mar<<endl;

    return 0;
}