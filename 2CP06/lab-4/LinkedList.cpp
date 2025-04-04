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

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void addAtHead(int val)
    {
        Node *new_node = new Node(val);

        new_node->next = head;
        head = new_node;
    }

    void addAtLast(int val)
    {
        Node *tp = head;
        Node *new_node = new Node(val);

        if (head == NULL)
        {
            head = new_node;
            return;
        }

        while (tp->next)
        {
            tp = tp->next;
        }

        tp->next = new_node;
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
            prev = tp;
            tp = tp->next;
            pos--;
        }

        if (pos)
        {
            cout << "Position doesn't exist;" << endl;
            return;
        }

        prev->next = tp->next;
    }

    void deleteFirstOccurence(int del)
    {
        Node *tp = head;

        if (head == NULL)
        {
            cout << "List empty." << endl;
            return;
        }

        Node *prev = NULL;

        if (head->val == del)
        {
            deleteAtpos(0);
            return;
        }

        while (tp && tp->val != del)
        {
            prev = tp;
            tp = tp->next;
        }

        if (!tp)
        {
            cout << "Element Does not exist" << endl;
            return;
        }

        prev->next = tp->next;
    }

    void deleteAllOccurence(int del)
    {
        Node *tp = head;

        if (head == NULL)
        {
            cout << "List empty." << endl;
            return;
        }

        Node *prev = NULL;
        bool flag = true;
        while (tp)
        {
            while (tp && tp == head && head->val == del)
            {
                deleteAtpos(0);
                tp = head;
                flag = false;
            }
            while (tp && tp->val == del)
            {
                prev->next = tp->next;
                tp = tp->next;
                flag = false;
            }
            prev = tp;
            tp = tp->next;
        }

        if (!tp && flag)
        {
            cout << "Element Does not exist" << endl;
            return;
        }

        // prev->next = tp->next;
    }

    void insertAtpos(int pos, int val)
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
            addAtHead(val);
            return;
        }

        Node *prev = NULL;

        while (tp && pos != 0)
        {
            prev = tp;
            tp = tp->next;
            pos--;
        }

        if (pos)
        {
            cout << "Position " << pos << " doesn't exist;" << endl;
            return;
        }

        prev->next = new_node;
        new_node->next = tp;
    }

    void display()
    {
        Node *tp = head;

        while (tp)
        {
            cout << tp->val << " -> ";
            tp = tp->next;
        }
        cout << "NULL" << endl;
    }

    void insertBeforeVal(int ins, int value)
    {
        int len = 0;

        Node *tp = head;
        if (!head)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        while (tp && tp->val != ins)
        {
            len++;
            tp = tp->next;
        }

        if (tp)
            insertAtpos(len, value);
        else
            cout << "Element doesn't exist to insert" << endl;
    }

    void insertAfterVal(int ins, int value)
    {
        int len = 0;

        Node *tp = head;
        if (!head)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        while (tp && tp->val != ins)
        {
            len++;
            tp = tp->next;
        }

        if (tp)
            insertAtpos(len + 1, value);
        else
            cout << "Element doesn't exist to insert" << endl;
    }

    void deleteBeforeVal(int del)
    {
        Node *tp = head;
        int len = 0;

        if (head == NULL)
        {
            cout << "List empty." << endl;
            return;
        }

        while (tp && tp->val != del)
        {
            tp = tp->next;

            // cout << tp->val << "   ";
            len++;
            // cout << " LEN=" << len << " ";
        }

        if (tp)
            deleteAtpos(len - 1);
        else
            cout << "Element doest exist to compare" << endl;
    }

    void deleteAfterVal(int del)
    {
        Node *tp = head;
        int len = 0;

        if (head == NULL)
        {
            cout << "List empty." << endl;
            return;
        }

        while (tp && tp->val != del)
        {
            tp = tp->next;
            len++;
        }

        if (tp)
            deleteAtpos(len+1);
        else
            cout << "Element doest exist to compare" << endl;
    }

    void reverseList(){
        if(!head || ! (head->next)){
            return;
        }

        Node * prev = NULL;
        Node * tp = head;

        while(tp){
            Node* nxt = tp->next;
            tp->next = prev;
            prev = tp;
            tp = nxt;
        }
        head = prev;
    }
};

int main()
{
    LinkedList ll;
    ll.addAtHead(5);
    ll.addAtHead(4);
    ll.addAtHead(3);
    ll.addAtHead(2);
    ll.display();

    ll.addAtLast(6);
    ll.addAtLast(7);
    ll.addAtLast(8);
    ll.display();

    ll.deleteAtpos(3);
    ll.deleteAtpos(0);
    ll.deleteAtpos(11);
    ll.display();

    ll.insertAtpos(0, 4);
    ll.insertAtpos(3, 99);
    ll.insertAtpos(5, 100);
    ll.insertAtpos(50, 100);
    ll.display();

    ll.deleteFirstOccurence(4);
    ll.deleteFirstOccurence(100);
    // ll.display();

    ll.insertAtpos(0, 4);
    ll.insertAtpos(1, 4);
    ll.insertAtpos(3, 4);
    ll.insertAtpos(4, 4);
    // ll.display();

    // ll.deleteAllOccurence(4);
    // ll.display();
    // ll.deleteAllOccurence(999);

    ll.insertAfterVal(8, 9090);
    ll.insertBeforeVal(8, 9090);
    ll.insertAfterVal(4, 9090);
    ll.insertBeforeVal(4, 9090);
    ll.display();

    cout<<"DEL "<<endl;
    ll.deleteAfterVal(4);
    ll.display();

    ll.deleteBeforeVal(4);
    ll.display();

    ll.reverseList();
    ll.display();
}