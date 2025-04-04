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

class Stack
{
private:
    Node* tos;
public:
    Stack(){
        tos = nullptr;
    }
    
    int top(){
        if(tos!=nullptr){
            return tos->val;
        }
        cout<<"Stack is empty";
        return -1e9;
    }

    void push(int val){
        Node* new_node = new Node(val);
        new_node->next = tos;
        tos = new_node;
    }

    void pop(){
        if(tos==nullptr){
            cout<<"Stack is empty";
            return;
        }
        Node* temp = tos;
        tos = tos->next;
        delete temp;
    }

    bool empty(){
        return tos == nullptr;
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.top()<<endl;
    st.pop();
    if(st.empty()){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();

    if(st.empty()){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
}

