#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void InsertNode(Node *&root)
{
    int data;
    cout << "Enter data for node : ";
    cin >> data;

    if (data == -1)
    {
        return;
    }

    root = new Node(data);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for left of " << temp->data << " node : ";
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for right of " << temp->data << " node : ";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

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
}
void PreOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
void PostOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);

    cout << root->data << " ";
}
void InOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void ReverseOrderTraversal(Node *root)
{
    queue<Node *> q;
    stack<int> st;
    vector<int> temp;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        st.push(temp->data);
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

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

void CountLeafNodes(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    CountLeafNodes(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    CountLeafNodes(root->right, count);
}
int HeightBinaryTree(Node *root, int &depth)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = HeightBinaryTree(root->left, depth);
    int right = HeightBinaryTree(root->right, depth);

    int Height = max(left, right) + 1;
    return Height;
}
pair<int, int> DiameterBinaryTree(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = DiameterBinaryTree(root->left);
    pair<int, int> right = DiameterBinaryTree(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
pair<bool, int> BalancedTree(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = BalancedTree(root->left);
    pair<bool, int> right = BalancedTree(root->right);

    bool opt1 = left.first;
    bool opt2 = right.first;
    bool opt3 = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    if (opt1 && opt2 && opt3)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}
int bottomLeftValue(Node *root)
{
    queue<Node *> q;
    q.push(root);

    int last = 0;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == 0)
            {
                last = temp->data;
            }

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

    return last;
}
int main()
{
    Node *root = NULL;
    InsertNode(root);
    cout << endl;
    cout << "level Order Traversal : " << endl;
    LevelOrderTraversal(root);
    cout << "PreOrder Traversal : ";
    PreOrderTraversal(root);
    cout << endl;
    cout << "PostOrder Traversal : ";
    PostOrderTraversal(root);
    cout << endl;
    cout << "Inorder Traversal : ";
    InOrderTraversal(root);
    cout << endl;
    cout << "Reverse Order Traversal : ";
    ReverseOrderTraversal(root);
    cout << endl;
    int LeafNodeCount = 0;
    cout << endl;
    CountLeafNodes(root, LeafNodeCount);
    cout << "Leaf Node Count : " << LeafNodeCount << endl;
    int depth = 1;
    int height = HeightBinaryTree(root, depth);
    cout << "Height of Bianry Tree : " << height << endl;
    cout << "Diameter of Binary Tree : " << DiameterBinaryTree(root).first << endl;
    cout << "Balanced Tree : " << BalancedTree(root).first << endl;
    cout << "Bottom Left Value : " << bottomLeftValue(root);
    cout << endl;
    return 0;
}