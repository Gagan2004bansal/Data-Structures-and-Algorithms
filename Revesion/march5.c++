// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META
#include <iostream>
#include <queue>
#include <map>
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
    cout << "Insert Data for node : ";
    cin >> data;

    if (data == -1)
    {
        return;
    }

    queue<Node *> q;
    root = new Node(data);
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
vector<int> TopView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    queue<pair<Node *, int> > q;
    q.push(make_pair(root, 0));

    map<int, int> topNode;

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int index = temp.second;

        if (topNode.find(index) == topNode.end())
        {
            topNode[index] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, index - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, index + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}
vector<int> BottomView(Node *root)
{
    vector<int> ans;
    queue<pair<Node *, int> > q;
    q.push(make_pair(root, 0));

    map<int, int> bottomNode;

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *bottom = temp.first;
        int index = temp.second;

        bottomNode[index] = bottom->data;

        if (bottom->left)
        {
            q.push(make_pair(bottom->left, index - 1));
        }

        if (bottom->right)
        {
            q.push(make_pair(bottom->right, index + 1));
        }
    }

    for (auto i : bottomNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}
void LeftView(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    LeftView(root->left, level + 1, ans);
    LeftView(root->right, level + 1, ans);
}
void RightView(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    RightView(root->right, level + 1, ans);
    RightView(root->left, level + 1, ans);
}
int main()
{
    Node *root = NULL;
    InsertNode(root);

    vector<int> res = TopView(root);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> res1 = BottomView(root);
    for (auto i : res1)
    {
        cout << i << " ";
    }
    cout << endl;

    int level = 0;
    vector<int> res2;
    LeftView(root, level, res2);
    for (auto i : res2)
    {
        cout << i << " ";
    }
    cout << endl;

    int level1 = 0;
    vector<int> res3;
    RightView(root, level1, res3);
    for (auto i : res3)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}