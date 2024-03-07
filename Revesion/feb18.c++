// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
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
    cout << "Enter Data for root : ";
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
        cout << "Enter data for left of " << temp->data << " Node : ";
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for right of " << temp->data << " Node : ";
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

    map<int, int> topNode;
    queue<pair<Node *, int> > q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int Index = temp.second;

        if (topNode.find(Index) == topNode.end())
        {
            topNode[Index] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, Index - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, Index + 1));
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
    map<int, int> BottomNode;
    queue<pair<Node *, int> > q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int index = temp.second;

        BottomNode[index] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, index - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, index + 1));
        }
    }

    for (auto i : BottomNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}
void LeftView(Node *root, int level, vector<int> &result2)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    if (result2.size() == level)
    {
        result2.push_back(root->data);
    }

    LeftView(root->left, level + 1, result2);
    LeftView(root->right, level + 1, result2);
}
void RightView(Node *root, vector<int> &result3, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (result3.size() == level)
    {
        result3.push_back(root->data);
    }

    RightView(root->right, result3, level + 1);
    RightView(root->left, result3, level + 1);
}
void VerticalOrderTraversal(Node *root)
{
    vector<int> ans;
    map<int, map<int, vector<int> > > nodes;
    queue<pair<Node *, pair<int, int> > > q;

    if (root == nullptr)
    {
        return;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int> > temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int index = temp.second.first;
        int level = temp.second.second;

        nodes[index][level].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(index - 1, level + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(index + 1, level + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    Node *root;
    InsertNode(root);
    cout << endl;
    cout << "Top View : ";
    vector<int> result = TopView(root);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Bottom View : ";
    vector<int> result1 = BottomView(root);
    for (auto i : result1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Left View : ";
    vector<int> result2;
    int level = 0;
    LeftView(root, level, result2);
    for (auto i : result2)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Right View : ";
    vector<int> result3;
    RightView(root, result3, level);
    for (auto i : result3)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Vertical Order Traversal : ";
    VerticalOrderTraversal(root);

    return 0;
}