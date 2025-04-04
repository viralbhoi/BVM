#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }

    void addNode(int val)
    {
        Node *new_node = new Node(val);
        if (root == nullptr)
        {
            root = new_node;
            return;
        }

        Node *q = root;
        Node *p = nullptr;

        while (q != NULL)
        {
            p = q;

            if (val < (q->val))
                q = (q->left);
            else
                q = (q->right);
        }

        if (val < (p->val))
            p->left = new_node;
        else
            p->right = new_node;
    }

    bool Find(int key)
    {

        if (root == nullptr)
            return false;

        Node *q = root;

        while (q != NULL)
        {

            if (q->val == key)
                return true;

            if (key < (q->val))
                q = (q->left);
            else
                q = (q->right);
        }

        return false;
    }

    // void deleteNode(int key)
    // {
    //     if (root == nullptr)
    //         return;

    //     Node *q = root;
    //     Node *p = nullptr;

    //     int Case = -1;
    //     while (q != NULL)
    //     {
    //         p = q;

    //         if (key < (q->val))
    //             q = (q->left);
    //         else
    //             q = (q->right);

    //         if (q->val == key)
    //         {
    //             if (q->left == nullptr && q->right == nullptr)
    //             {
    //                 Case = 1;
    //                 break;
    //             }

    //             if (q->left == nullptr || q->right == nullptr)
    //             {
    //                 Case = 2;
    //                 break;
    //             }

    //             Case = 3;
    //         }
    //     }

    //     if (Case == -1)
    //     {
    //         return;
    //     }
    //     else if (Case == 1)
    //     {
    //         if (p->left == q)
    //         {
    //             p->left = nullptr;
    //         }
    //         else
    //         {
    //             p->right = nullptr;
    //         }
    //     }
    //     else if (Case == 2)
    //     {
    //         if (q->left == nullptr)
    //         {
    //             if (p->left == q)
    //             {
    //                 p->left = q->right;
    //             }
    //             else
    //             {
    //                 p->right = q->right;
    //             }
    //         }
    //         else
    //         {
    //             if (p->left == q)
    //             {
    //                 p->left = q->left;
    //             }
    //             else
    //             {
    //                 p->right = q->left;
    //             }
    //         }
    //     }
    // }

    Node *ROOT() { return root; }
};

void inorder(Node *rt)
{ // left root right
    if (rt == NULL)
        return;

    inorder(rt->left);
    cout << rt->val << "  ";
    inorder(rt->right);
}

void preorder(Node *rt)
{ // root left right
    if (rt == NULL)
        return;

    cout << rt->val << "  ";
    preorder(rt->left);
    preorder(rt->right);
}

void postorder(Node *rt)
{ // left right root
    if (rt == NULL)
        return;

    postorder(rt->left);
    postorder(rt->right);
    cout << rt->val << "  ";
}

int main()
{
    BST b1;
    b1.addNode(5);
    b1.addNode(3);

    b1.addNode(6);
    b1.addNode(1);

    b1.addNode(4);

    inorder(b1.ROOT());
    cout << endl;
    preorder(b1.ROOT());
    cout << endl;
    postorder(b1.ROOT());
    cout << endl;

    if (b1.Find(5))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    if (b1.Find(2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    if (b1.Find(4))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    if (b1.Find(7))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    b1.deleteNode(4);
    inorder(b1.ROOT());
    cout << endl;

    b1.deleteNode(1);
    inorder(b1.ROOT());
    cout << endl;

    b1.deleteNode(6);
    inorder(b1.ROOT());
    cout << endl;
}