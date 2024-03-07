// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

// Ques 1   k-Sum Path in Binary Tree  leetcode : https://leetcode.com/problems/path-sum-iii/description/
// Ques 2   k-th Ancestor in Binary Tree leetcode : https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
#include <iostream>
#include <vector>
#include <queue>
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
        this->left = nullptr;
        this->right = nullptr;
    }
};
void InsertNode(Node *&root)
{
    int data;
    cout << "Enter data for root : ";
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
        cout << "Enter Node for left of " << temp->data << " node : ";
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter Node for right of " << temp->data << " node : ";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
Node *Solve(Node *root, int node, int &k)
{
    // Base Case
    if (root == NULL)
    {
        return nullptr;
    }
    // jis point me hmari node match kr jaye usse niche hme jana he nhi h
    if (root->data == node)
    {
        return root;
    }

    Node *leftdata = Solve(root->left, node, k);
    Node *rightdata = Solve(root->right, node, k);

    if (leftdata != nullptr && rightdata == nullptr)
    {
        k--;
        if (k <= 0)
        {
            return root;
        }
        return leftdata;
    }
    if (leftdata == nullptr && rightdata != nullptr)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightdata;
    }

    return nullptr;
}
void Kth_Ancestor(Node *root)
{
    int node;
    cout << "Enter Node for which you want kth ancestor : ";
    cin >> node;

    int k;
    cout << "Enter which Kth ancestor you want : ";
    cin >> k;

    Node *result = Solve(root, node, k);
    if (result == nullptr || result->data == node)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result->data << endl;
    }
}
void ksumPath(Node *root, vector<int> path, int k, int &count)
{
    // Base  Case
    if (root == nullptr)
    {
        return;
    }

    path.push_back(root->data);
    ksumPath(root->left, path, k, count);
    ksumPath(root->right, path, k, count);

    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }

    path.pop_back();
}
int main()
{
    Node *root = nullptr;
    InsertNode(root);
    vector<int> path;
    int count = 0;
    int k;
    cout << "Enter K : ";
    cin >> k;
    ksumPath(root, path, k, count);

    cout << "Total Path : " << count << endl;

    Kth_Ancestor(root);

    return 0;
}