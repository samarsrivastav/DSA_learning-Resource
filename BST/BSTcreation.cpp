#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        right = left = NULL;
    }
};
Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}
void printInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // left, root, right
    printInOrder(root->left);
    cout << root->key << " ,";
    printInOrder(root->right);
}
bool search(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->key == key)
    {
        return true;
    }
    if (root->key > key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}
Node *FindMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *remove(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (key < root->key)
    {
        root->left = remove(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = remove(root->right, key);
    }
    else
    {
        // No child
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // 1 CHild
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // 2 Child
        else
        {
            Node *temp = FindMin(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }
    return root;
}
void PrintRange(Node *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    if (k1 <= root->key and root->key <= k2)
    {
        PrintRange(root->left, k1, k2);
        cout << root->key << " ";
        PrintRange(root->right, k1, k2);
    }
    else if (root->key > k2)
    {
        PrintRange(root->left, k1, k2);
    }
    else
    {
        PrintRange(root->left, k1, k2);
    }
}
int main()
{
    Node *root = NULL;
    vector<int> v = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (auto x : v)
    {
        root = insert(root, x);
    }
    printInOrder(root);
    cout << endl;
    //      << search(root, 4) << endl;
    remove(root, 3);
    printInOrder(root);
    cout << endl;
    PrintRange(root, 3, 8);
    cout << endl;
}