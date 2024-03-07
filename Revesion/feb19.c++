// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

// Ques 1 ==> Sum of Longest Path in Binary Tree
// Ques 2 ==> Lowest Common Ancestor in Binary Tree [LCA OF BINARY TREE]
#include <iostream>
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
    cout << "Enter data for the root : ";
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
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
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
void SumofLongestPath(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    // Base Case
    if (root == nullptr)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum = sum + root->data;
    SumofLongestPath(root->left, sum, maxSum, len + 1, maxLen);
    SumofLongestPath(root->right, sum, maxSum, len + 1, maxLen);
}
Node *LCAofBinaryTree(Node *root, int n1, int n2)
{
    // Base Case
    if (root == nullptr)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left = LCAofBinaryTree(root->left, n1, n2);
    Node *right = LCAofBinaryTree(root->right, n1, n2);

    if (left != nullptr && right != nullptr)
    {
        return root;
    }
    else if (left != nullptr && right == nullptr)
    {
        return left;
    }
    else if (left == nullptr && right != nullptr)
    {
        return right;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    Node *root = nullptr;
    InsertNode(root);

    levelOrderTraversal(root);
    cout << endl;

    int maxSum = INT_MIN, maxLen = 0;
    int sum = 0, len = 0;
    SumofLongestPath(root, sum, maxSum, len, maxLen);
    cout << "Sum of Longest Path is " << maxSum << endl;

    int n1, n2;
    cout << "Enter n1 : ";
    cin >> n1;
    cout << "Enter n2 : ";
    cin >> n2;
    Node *ans = LCAofBinaryTree(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is ";
    cout << ans->data << endl;

    return 0;
}