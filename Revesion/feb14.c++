// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

#include <iostream>
#include <vector>
#include <stack>
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
        this->left = NULL;
        this->right = NULL;
    }
};
void InsertData(Node *&root, vector<int> nums)
{
    if (nums.size() <= 0)
    {
        return;
    }
    root = new Node(nums[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (i < nums.size())
    {
        Node *temp = q.front();
        q.pop();

        if (i < nums.size())
        {
            temp->left = new Node(nums[i++]);
            q.push(temp->left);
        }

        if (i < nums.size())
        {
            temp->right = new Node(nums[i++]);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(Node *root)
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
void ReverseOrderTraversal(Node *root)
{
    stack<Node *> s;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    while (!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }
}
void LeafNode(Node *root, int &count, vector<int> &StoreLeafNode)
{
    if (root == NULL)
    {
        return;
    }

    LeafNode(root->left, count, StoreLeafNode);

    if (root->left == NULL && root->right == NULL)
    {
        // cout << root -> data << " ";
        count++;
        StoreLeafNode.push_back(root->data);
    }

    LeafNode(root->right, count, StoreLeafNode);
}
int DepthHeightOfBinaryTree(Node *root, int depth)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = DepthHeightOfBinaryTree(root->left, depth);
    int right = DepthHeightOfBinaryTree(root->right, depth);

    depth = max(left, right) + 1;

    return depth;
}
pair<int, int> DiameterWidth(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = DiameterWidth(root->left);
    pair<int, int> right = DiameterWidth(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
int main()
{
    Node *root = NULL;
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    InsertData(root, nums);
    // levelOrderTraversal(root);
    // ReverseOrderTraversal(root);
    int count = 0;
    vector<int> StoreLeafNode;
    LeafNode(root, count, StoreLeafNode);
    // cout << endl << count << endl;

    // for(int i = 0; i<StoreLeafNode.size() ; i++){
    //     cout << StoreLeafNode[i] << " ";
    // }

    int depth = 0;
    int height = DepthHeightOfBinaryTree(root, depth);
    // cout << height - 1 << endl;

    cout << DiameterWidth(root).first << endl;

    return 0;
}