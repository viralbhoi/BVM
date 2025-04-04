#include <bits/stdc++.h>
using namespace std;

struct AVLNode
{

    int key;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};
class AVLTree
{
    AVLNode *root;

public:
    AVLTree()
    {
        root = nullptr;
    }
    int height(AVLNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }
    int balanceFactor(AVLNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }
    AVLNode *rightrotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *hold = x->right;
        x->right = y;
        y->left = hold;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    AVLNode *leftrotate(AVLNode *y)
    {
        AVLNode *x = y->right;
        AVLNode *hold = x->left;
        x->left = y;
        y->right = hold;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    AVLNode *insertnode(AVLNode *node, int key)
    {
        if (node == nullptr)
        {
            return (new AVLNode(key));
        }
        if (key < node->key)
        {
            node->left = insertnode(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insertnode(node->right, key);
        }
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = balanceFactor(node);
        if (balance > 1 && key < node->left->key)
        {
            return rightrotate(node);
        }
        if (balance < -1 && key > node->right->key)
        {
            return leftrotate(node);
        }
        return node;
    }
    void inorder(AVLNode *root)

    {
        if (root != nullptr)
        {

            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
    void insertnode(int key) { root = insertnode(root, key); }
    AVLNode *rt()
    {
        return root;
    }
};
int main()
{
    AVLTree e1;
    e1.insertnode(10);
    e1.insertnode(11);
    e1.inorder(e1.rt());
}
