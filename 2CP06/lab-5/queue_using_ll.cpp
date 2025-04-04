#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class Queue
{
private:
    Node* f;
    Node* r;
public:
    Queue(){
        f = nullptr;
        r = nullptr;
    }
    
    int front(){
        if(f!=nullptr){
            return f->val;
        }
        cout<<"Queue is empty";
        return -1e9;
    }

    void push(int val){
        Node* new_node = new Node(val);
        if(!f){
            f = r = new_node;
        }
        r->next = new_node;
        r=r->next;
    }

    void pop(){
        if(!f){
            cout<<"Queue is empty"<<endl;
        }

        Node* temp = f;
        f= f->next;
        delete temp;
    }

    bool empty(){
        return f == nullptr;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.front()<<endl;
    q.pop();
    if(q.empty()){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();

    if(q.empty()){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
}