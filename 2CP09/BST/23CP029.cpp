#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include "zoo-week02.h"

using namespace std;

// ******************************** Animal Class declaration ********************************************

Animal::Animal(string nm, double wt)
{
    name = nm;
    weight = wt;
}

// ******************************** Type Class declaration ********************************************

Type::Type(string nm, double wt, string tp) : Animal(nm, wt)
{
    type = tp;
}

// ******************************** Animal Class declaration ********************************************

Species::Species(string nm, double wt, string tp, string sp) : Type(nm, wt, tp)
{
    species = sp;
}

// ******************************** Node Class declaration ********************************************
Node::Node(Animal *a) : a(a), left(nullptr), right(nullptr), parent(nullptr), bLeft(false) {}

Node::~Node()
{
    delete a;
}

// ******************************** BST Class declaration ********************************************
bool BST::isEmpty()
{
    return root == nullptr;
}

Node *BST::search(double wt)
{
    Node *current = root;
    while (current)
    {
        double currWt = current->getAnimalPtr()->getWeight();
        if (abs(currWt - wt) <= error)
            return current;
        else if (wt < currWt)
            current = current->getLeft();
        else
            current = current->getRight();
    }
    return nullptr;
}

Node *BST::search(Node *nd, string nm)
{
    if (!nd)
        return nullptr;
    Node *leftResult = search(nd->getLeft(), nm);
    if (leftResult)
        return leftResult;
    if (nd->getAnimalPtr()->getName() == nm)
        return nd;
    return search(nd->getRight(), nm);
}

Node *BST::search(string nm)
{
    return search(root, nm);
}

bool BST::addNode(Animal *a)
{
    Node *newNode = new Node(a);
    if (!root)
    {
        root = newNode;
        return true;
    }

    Node *current = root;
    Node *parent = nullptr;

    while (current)
    {
        parent = current;
        if (a->getWeight() < current->getAnimalPtr()->getWeight())
        {
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
    }

    if (a->getWeight() < parent->getAnimalPtr()->getWeight())
    {
        parent->setLeft(newNode);
        newNode->setLeft();
    }
    else
    {
        parent->setRight(newNode);
        newNode->setRight();
    }
    newNode->setParent(parent);
    return true;
}

Node *BST::findInorderSuccessor(Node *nd)
{
    if (!nd->getRight())
        return nullptr;

    Node *successor = nd->getRight();
    while (successor->getLeft())
    {
        successor = successor->getLeft();
    }
    return successor;
}

bool BST::deleteNode(string nme)
{
    Node *target = search(nme);
    if (!target)
        return false;

    Node *parent = target->getParent();

    if (!target->getLeft() && !target->getRight())
    {
        if (parent)
        {
            if (parent->getLeft())
                parent->setLeft(nullptr);
            else
                parent->setRight(nullptr);
        }
        else
        {
            root = nullptr;
        }
        delete target;
        return true;
    }

    if (!target->getLeft() || !target->getRight())
    {
        Node *child = target->getLeft() ? target->getLeft() : target->getRight();
        if (parent)
        {
            if (target->getLeft())
                parent->setLeft(child);
            else
                parent->setRight(child);
            child->setParent(parent);
        }
        else
        {
            root = child;
            child->setParent(nullptr);
        }
        delete target;
        return true;
    }

    Node *successor = findInorderSuccessor(target);
    Animal *temp = target->getAnimalPtr();
    target->setAnimalptr(successor->getAnimalPtr());
    successor->setAnimalptr(temp);

    Node *sParent = successor->getParent();
    Node *sChild = successor->getRight();

    if (sParent != target)
    {
        sParent->setLeft(sChild);
    }
    else
    {
        sParent->setRight(sChild);
    }

    if (sChild)
    {
        sChild->setParent(sParent);
        sChild->setLeft();
    }

    delete successor;
    return true;
}

double BST::getTotalWeightInRange(double low, double hi)
{
    double total = 0.0;
    stack<Node *> s;
    Node *curr = root;

    while (!s.empty() || curr)
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->getLeft();
        }
        curr = s.top();
        s.pop();

        double wt = curr->getAnimalPtr()->getWeight();
        if (wt > hi)
            break;
        if (wt >= low)
            total += wt;

        curr = curr->getRight();
    }
    return total;
}

double BST::getTotalWeightInRange(double low, double hi, string species)
{
    double total = 0.0;
    stack<Node *> s;
    Node *curr = root;

    while (!s.empty() || curr)
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->getLeft();
        }
        curr = s.top();
        s.pop();

        double wt = curr->getAnimalPtr()->getWeight();
        string sp = curr->getAnimalPtr()->getSpecies();

        if (wt > hi)
            break;
        if (wt >= low && (species.empty() || sp == species))
        {
            total += wt;
        }

        curr = curr->getRight();
    }
    return total;
}

Animal* createAnimal(const string& species, const string& name, double weight) {
    if (species == "peacock" || species == "parrot") {
        return new Species(name, weight, "bird", species);
    }
    if (species == "tiger" || species == "monkey") {
        return new Species(name, weight, "mammal", species);
    }
    return nullptr;
}

int main()
{
    BST zoo;

    string command;

    do
    {
        cin >> command;

        istringstream iss(command);
        vector<string> comm;
        string word;

        while (iss>>word)
            comm.push_back(word);


        if (comm[0] == "birth")
        {
            Animal* animal = createAnimal(comm[1], comm[2], stod(comm[3]));
        }
        else if (comm[0] == "death")
        {
            zoo.deleteNode(comm[1]);
        }
        else if (comm[0]=="query")
        {
            if(comm.size() == 4){
                zoo.getTotalWeightInRange(stod(comm[1]),stod(comm[2]));
            }else{
                zoo.getTotalWeightInRange(stod(comm[1]),stod(comm[2]),comm[3]);
            }
        }else if(comm[0] == "exit"){
            break;
        }else{
            cout<<"INVALID"<<endl;
        }
    } while (command != "exit");
}
