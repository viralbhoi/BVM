#include <iostream>
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
        head = NULL;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtLast(int val)
    {
        Node *tp = head;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        while (tp->next)
        {
            tp = tp->next;
        }

        tp->next = newNode;
        newNode->prev = tp;
    }

    void insertAtPos(int pos, int val)
    {
        Node *tp = head;
        Node *new_node = new Node(val);

        if (head == NULL && pos == 0)
        {
            head = new_node;
            return;
        }

        if (pos == 0)
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            return;
        }

        while (tp && pos != 0)
        {
            tp = tp->next;
            pos--;
        }

        if (pos)
        {
            cout << "Position " << pos << " doesn't exist;" << endl;
            return;
        }

        tp=tp->prev;
        new_node->prev = tp;
        new_node->next = tp->next;
        tp->next = new_node;
        new_node->prev = tp;
    }

    void display(){
        Node* tp = head;
        while(tp){
            cout<<tp->val<<" -> ";
            tp = tp->next;
        }

        cout<<"NULL"<<endl;
    }

    void deleteAtpos(int pos)
    {
        Node *tp = head;

        if (head == NULL)
        {
            cout << "List empty." << endl;
            return;
        }

        if (pos == 0)
        {
            head = head->next;
            return;
        }

        Node *prev = NULL;

        while (tp && pos != 0)
        {
            tp = tp->next;
            pos--;
        }

        if (pos)
        {
            cout << "Position doesn't exist;" << endl;
            return;
        }

        tp = tp->prev;
        Node* temp = tp->next; 
        tp->next = temp->next;
        temp->next->prev = tp;

        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
};

int main(){
    doublyLinkedList dll;
    dll.insertAtHead(2);
    dll.insertAtLast(3);
    dll.insertAtLast(4);
    dll.display();
    dll.insertAtPos(1, 5);
    dll.display();
    dll.deleteAtpos(1);
    dll.display();
    dll.deleteAtpos(1);
    dll.display();

}
