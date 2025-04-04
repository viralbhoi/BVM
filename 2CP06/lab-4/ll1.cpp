#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class LinkedList {
    Node *head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node *tp = head;
        while (tp) {
            Node *nextNode = tp->next;
            delete tp;
            tp = nextNode;
        }
    }

    void addAtHead(int val) {
        Node *new_node = new Node(val);
        new_node->next = head;
        head = new_node;
    }

    void addAtLast(int val) {
        Node *new_node = new Node(val);
        if (!head) {
            head = new_node;
            return;
        }
        Node *tp = head;
        while (tp->next) {
            tp = tp->next;
        }
        tp->next = new_node;
    }

    void deleteAtpos(int pos) {
        if (!head) {
            cout << "List empty." << endl;
            return;
        }

        Node *tp = head;
        if (pos == 0) {
            head = head->next;
            delete tp;  // Free memory
            return;
        }

        Node *prev = NULL;
        while (tp && pos != 0) {
            prev = tp;
            tp = tp->next;
            pos--;
        }

        if (!tp) {
            cout << "Position doesn't exist;" << endl;
            return;
        }

        prev->next = tp->next;
        delete tp;  // Free memory
    }

    void deleteFirstOccurence(int del) {
        if (!head) {
            cout << "List empty." << endl;
            return;
        }

        Node *tp = head, *prev = NULL;
        if (head->val == del) {
            head = head->next;
            delete tp;
            return;
        }

        while (tp && tp->val != del) {
            prev = tp;
            tp = tp->next;
        }

        if (!tp) {
            cout << "Element does not exist" << endl;
            return;
        }

        prev->next = tp->next;
        delete tp;
    }

    void deleteAllOccurence(int del) {
        if (!head) {
            cout << "List empty." << endl;
            return;
        }

        Node *tp = head, *prev = NULL;
        while (tp && head->val == del) { // Delete occurrences at head
            head = head->next;
            delete tp;
            tp = head;
        }

        while (tp) {
            if (tp->val == del) {
                prev->next = tp->next;
                delete tp;
                tp = prev->next;
            } else {
                prev = tp;
                tp = tp->next;
            }
        }
    }

    void insertAtpos(int pos, int val) {
        Node *new_node = new Node(val);

        if (pos == 0) {
            addAtHead(val);
            return;
        }

        Node *tp = head, *prev = NULL;
        while (tp && pos != 0) {
            prev = tp;
            tp = tp->next;
            pos--;
        }

        if (pos) {
            cout << "Position doesn't exist;" << endl;
            delete new_node; // Prevent memory leak
            return;
        }

        prev->next = new_node;
        new_node->next = tp;
    }

    void insertBeforeVal(int ins, int value) {
        if (!head) {
            cout << "List is Empty!" << endl;
            return;
        }

        Node *tp = head;
        int pos = 0;
        while (tp && tp->val != ins) {
            pos++;
            tp = tp->next;
        }

        if (tp)
            insertAtpos(pos, value);
        else
            cout << "Element doesn't exist to insert" << endl;
    }

    void insertAfterVal(int ins, int value) {
        if (!head) {
            cout << "List is Empty!" << endl;
            return;
        }

        Node *tp = head;
        int pos = 0;
        while (tp && tp->val != ins) {
            pos++;
            tp = tp->next;
        }

        if (tp)
            insertAtpos(pos + 1, value);
        else
            cout << "Element doesn't exist to insert" << endl;
    }

    void deleteBeforeVal(int del) {
        if (!head || head->next == NULL) {
            cout << "List is empty or too short." << endl;
            return;
        }

        Node *tp = head, *prev = NULL;
        int pos = 0;
        while (tp && tp->val != del) {
            prev = tp;
            tp = tp->next;
            pos++;
        }

        if (!tp || pos < 1) {
            cout << "Element doesn't exist to compare" << endl;
            return;
        }

        deleteAtpos(pos - 1);
    }

    void deleteAfterVal(int del) {
        if (!head) {
            cout << "List empty." << endl;
            return;
        }

        Node *tp = head;
        int pos = 0;
        while (tp && tp->val != del) {
            tp = tp->next;
            pos++;
        }

        if (tp && tp->next)
            deleteAtpos(pos + 1);
        else
            cout << "No element exists after given value" << endl;
    }

    void reverseList() {
        if (!head || !head->next)
            return;

        Node *prev = NULL, *tp = head, *nxt = NULL;
        while (tp) {
            nxt = tp->next;
            tp->next = prev;
            prev = tp;
            tp = nxt;
        }
        head = prev;
    }

    void display() {
        Node *tp = head;
        while (tp) {
            cout << tp->val << " -> ";
            tp = tp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
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
    ll.display();

    ll.insertAfterVal(8, 9090);
    ll.insertBeforeVal(8, 9090);
    ll.insertAfterVal(4, 9090);
    ll.insertBeforeVal(4, 9090);
    ll.display();

    cout << "DEL" << endl;
    ll.deleteAfterVal(4);
    ll.display();

    ll.deleteBeforeVal(4);
    ll.display();

    ll.reverseList();
    ll.display();

    return 0;
}
