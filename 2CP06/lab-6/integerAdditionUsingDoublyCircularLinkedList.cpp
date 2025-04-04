#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class doublyLinkedList
{
    Node *head;

public:
    doublyLinkedList()
    {
        head = new Node(0);
        head->next = head;
        head->prev = head;
    }

    void insertNum(string s){
        reverse(s.begin(),s.end());

        for(int i=0;i<s.size()-4;i+=5){
            string temp = "";
            for(int j=i;j<i+5;j++){
                temp = s[j] + temp;
            }
            insertAtLast(stoi(temp));
        }
    }

    void insertAtLast(int val)
    {
        head->val++;
        Node* ptr = head->prev;

        Node* new_node = new Node(val);

        new_node->next = head;
        new_node->prev = ptr;
        ptr->next = new_node;
        head->prev = new_node;
    }

    void display(){
        Node* tp = head->next;
        while(tp != head){
            cout<<tp->val<<" -> ";
            tp = tp->next;
        }

        cout<<"NULL"<<endl;
    }

    Node* getHead(){
        return head;
    }

    void displaynum(){
        Node* temp = head->prev;

        while(temp != head){
            cout<<temp->val;
            temp = temp->prev;
        }
        cout<<endl;
    }

    friend void bigDataAddition(doublyLinkedList,doublyLinkedList,doublyLinkedList);
};

void bigDataAddition(doublyLinkedList dl1, doublyLinkedList dl2 ,doublyLinkedList& res){
    

    int carry = 0;
    int len1 = dl1.getHead()->val;
    int len2 = dl1.getHead()->val;
    
    
    Node* t1 = dl1.getHead()->next;
    Node* t2 = dl2.getHead()->next;

    while(len1 && len2){
        int sum = t1->val + t2->val + carry;
        carry = sum / 100000;

        res.insertAtLast(sum%100000);
        t1 = t1->next;
        t2 = t2->next;
        len1--;
        len2--;
        
    }

    while(len1){
        int sum = t1->val+ carry;
        carry = sum / 100000;
        res.insertAtLast(sum%100000);
        t1 = t1->next;
        len1--;
    }

    while(len2){
        int sum = t2->val+ carry;
        carry = sum / 100000;
        res.insertAtLast(sum%100000);
        t2 = t2->next;
        len2--;
    }

    if(carry){
        res.insertAtLast(carry);
    }
}

int main(){

    string num1 ;
    cout<<"Enter Number: ";
    cin>>num1;

    string num2 ;
    cout<<"Enter Number: ";
    cin>>num2;

    doublyLinkedList dl1,dl2;
    dl1.insertNum(num1);
    dl2.insertNum(num2);

    dl1.display();
    dl2.display();

    doublyLinkedList res;
    bigDataAddition(dl1,dl2,res);

    res.display();
    res.displaynum();
}
