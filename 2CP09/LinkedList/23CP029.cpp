#include <bits/stdc++.h>
#include "givenclasses.h"
using namespace std;

// -------------------------------------Polygon---------------------------------------------

Polygon::Polygon(string name)
{
    this->name = name;
}

string Polygon::getName()
{
    return this->name;
}

bool Polygon::isBiggerByArea(Polygon &p)
{
    return this->getArea() > p.getArea();
}

bool Polygon::isBiggerByCircumference(Polygon &p)
{
    return this->getCircumference() > p.getCircumference();
}

// -------------------------------------Right Triangle---------------------------------------------

RightTriangle::RightTriangle(string name, double base, double height) : Polygon(name)
{
    this->base = base;
    this->height = height;
}

double RightTriangle::getArea()
{
    return (0.5 * base * height);
}

double RightTriangle::getCircumference()
{
    return (base + height + sqrt(base * base + height * height));
}

void RightTriangle::print()
{
    cout << "right-triangle " << getName() << " " << base << " " << height << endl;
}

// -------------------------------------Rectangle---------------------------------------------

Rectangle::Rectangle(string name, double base, double height) : Polygon(name)
{
    this->base = base;
    this->height = height;
}

double Rectangle::getArea()
{
    return base * height;
}

double Rectangle::getCircumference()
{
    return 2 * (base + height);
}

void Rectangle::print()
{
    cout << "rectangle " << getName() << " " << base << " " << height << endl;
}

// -------------------------------------Square---------------------------------------------

Square::Square(string name, double side) : Rectangle(name, side, side) {}

void Square::print()
{
    cout << "square " << getName() << " " << base << endl;
}

bool LinkedList::addNode(Polygon *p)
{
    Node *newNode = new Node(p);
    newNode->setNext(head);
    head = newNode;
    return true;
}

// -------------------------------------LinkedList---------------------------------------------

bool LinkedList::deleteNode(string nme)
{
    Node *temp = head;
    if (!head)
    {
        return 0;
    }

    if (head->getPolygonPtr()->getName() == nme)
    {
        Node *del = head;
        head = head->getNext();
        del->setNext(nullptr);
        delete del;
        return 1;
    }
    Node *prev = nullptr;
    while (temp != nullptr && temp->getPolygonPtr()->getName() != nme)
    {
        prev = temp;
        temp = temp->getNext();
    }

    if (temp != nullptr)
    {
        prev->setNext(temp->getNext());
        temp->updatePointer(nullptr);
        delete temp;
        return 1;
    }
    return 0;
}

void LinkedList::print()
{
    Node *temp = head;

    while (temp)
    {
        temp->getPolygonPtr()->print();
        temp = temp->getNext();
    }
}

double LinkedList::getTotalArea()
{
    double ans = 0;
    Node *temp = head;

    while (temp)
    {
        ans += temp->getPolygonPtr()->getArea();
        temp = temp->getNext();
    }

    return ans;
}

double LinkedList::getTotalCircumference()
{
    double ans = 0;
    Node *temp = head;

    while (temp)
    {
        ans += temp->getPolygonPtr()->getCircumference();
        temp = temp->getNext();
    }

    return ans;
}

// -------------------------------------Main---------------------------------------------

int main()
{
    LinkedList ll;

    while (true)
    {
        string operation;
        cin >> operation;

        if (operation == "add")
        {
            string poly;
            cin >> poly;

            if (poly == "right-triangle")
            {
                string name;
                cin >> name;
                double base, height;
                cin >> base >> height;

                RightTriangle *rt = new RightTriangle(name, base, height);
                ll.addNode(rt);
            }
            else if (poly == "rectangle")
            {
                string name;
                cin >> name;
                double base, height;
                cin >> base >> height;

                Rectangle *r = new Rectangle(name, base, height);
                ll.addNode(r);
            }
            else
            {
                string name;
                cin >> name;
                double side;
                cin >> side;

                Square *s = new Square(name, side);
                ll.addNode(s);
            }
        }
        else if (operation == "delete")
        {
            string name;
            cin >> name;
            ll.deleteNode(name);
        }
        else if (operation == "print")
        {
            string type;
            cin >> type;

            if (type == "area")
            {
                cout << ll.getTotalArea() << endl;
            }
            else
            {
                cout << ll.getTotalCircumference() << endl;
            }
        }
        else if (operation == "print-all")
        {
            ll.print();
        }
        else if (operation == "done")
        {
            break;
        }
        else
        {
            cout << "Invalid Operation" << endl;
        }
    }
}