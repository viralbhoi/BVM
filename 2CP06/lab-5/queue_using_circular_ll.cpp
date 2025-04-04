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
    
    Node* r;
public:
    Queue(){
        
        r = nullptr;
    }
    
    int front(){
        if(r!=nullptr){
            return r->next->val;
        }
        cout<<"Queue is empty";
        return -1e9;
    }

    void push(int val){
        Node* new_node = new Node(val);
        if(!r){
            r = new_node;
            r->next = r;
        }
        new_node->next = r->next;
        r->next = new_node;
        r=r->next;
    }

    void pop(){
        if(!r){
            cout<<"Queue is empty"<<endl;
            return;
        }
        if(r->next == r){
            r = NULL;
            return;
        }

        Node* temp = r->next;
        r->next= temp->next;
        delete temp;
    }

    bool empty(){
        return r == nullptr;
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