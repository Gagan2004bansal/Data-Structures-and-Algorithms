// Ques 1 : Maximum sum of two non adacent node in Binary Tree
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
pair<int, int> SumofNonAjacentNode(Node *root)
{
    if (root == nullptr)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = SumofNonAjacentNode(root->left);
    pair<int, int> right = SumofNonAjacentNode(root->right);

    pair<int, int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}
int positionFind(vector<int> in, int element, int inOrderStart, int inOrderEnd)
{
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (element == in[i])
        {
            return i;
        }
    }

    return -1;
}
Node *ConstructBinaryTree(vector<int> in, vector<int> pre, int n, int &preOrderIndex, int inOrderStart, int inOrderEnd)
{
    if (preOrderIndex >= n || inOrderStart > inOrderEnd)
    {
        return nullptr;
    }

    int element = pre[preOrderIndex];
    Node *root = new Node(element);
    int position = positionFind(in, element, inOrderStart, inOrderEnd);

    preOrderIndex++;

    root->left = ConstructBinaryTree(in, pre, n, preOrderIndex, inOrderStart, position - 1);
    root->right = ConstructBinaryTree(in, pre, n, preOrderIndex, position + 1, inOrderEnd);

    return root;
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
int main()
{
    Node *root = nullptr;
    InsertNode(root);

    pair<int, int> ans = SumofNonAjacentNode(root);
    cout << max(ans.first, ans.second) << endl;

    // Construct Binary Tree from Inorder and PreOrder traversal
    vector<int> in;
    vector<int> pre;

    for (int i = 0; i < 4; i++)
    {
        int input;
        cin >> input;
        in.push_back(input);
    }
    for (int i = 0; i < 4; i++)
    {
        int input;
        cin >> input;
        pre.push_back(input);
    }

    int n = 4;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = n - 1;

    Node *temp = ConstructBinaryTree(in, pre, n, preOrderIndex, inOrderStart, inOrderEnd);

    levelOrderTraversal(temp);

    return 0;
}