#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
Node *BuildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *n = new Node(d);
    n->left = BuildTree();
    n->right = BuildTree();
    return n;
}

Node *LevelOrderBuild()
{
    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *Current = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            Current->left = new Node(c1);
            q.push(Current->left);
        }
        if (c2 != -1)
        {
            Current->right = new Node(c2);
            q.push(Current->right);
        }
    }
    return root;
}
void printPreorder(Node *root) // root ->leftNode ->rightnode
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printInorder(Node *root) // leftNode ->root ->rightnode
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
void printPostOrder(Node *root) // leftNode ->rightnode->root
{
    if (root == NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}
void levelOrderPrint(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1, h2) + 1;
}
int diameter(Node *root)
{ //-->TIme Complexity O(N^2)
    if (root == NULL)
    {
        return 0;
    }
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left),
        D3 = diameter(root->right);

    return max(D1, max(D2, D3));
}
// Optimised Diameter
class HDpair
{
public:
    int height;
    int diameter;
};
HDpair OptDiameter(Node *root)
{
    HDpair p;
    if (root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }
    HDpair left = OptDiameter(root->left);
    HDpair right = OptDiameter(root->right);
    p.height = max(left.height, right.height) + 1;
    int D1 = left.height + right.height;
    int D2 = left.diameter;
    int D3 = right.diameter;

    p.diameter = max(D1, max(D2, D3));
    return p;
}
int main()
{
    Node *root = LevelOrderBuild();
    printPreorder(root);
    cout << endl;
    printInorder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    levelOrderPrint(root);
    cout << endl;
    cout << "Height: " << height(root) << endl;
    cout << " Diameter: " << OptDiameter(root).diameter << endl;
}