// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

// Today Task : Balanced Binary Tree
//            : Sum Tree
//            : Identical or Compare Two Binary Tree
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     // Constructor
//     Node(int data)
//     {
//         this->data = data;
//         this->left = nullptr;
//         this->right = nullptr;
//     }
// };
// void InsertNode(Node *&root)
// {
//     queue<Node *> q;
//     int data;
//     cin >> data;

//     if (data == -1)
//     {
//         return;
//     }

//     root = new Node(data);
//     q.push(root);

//     int i = 1;
//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         int leftData;
//         cout << "Enter data for left of " << temp->data << " node : ";
//         cin >> leftData;

//         if (leftData != -1)
//         {
//             temp->left = new Node(leftData);
//             q.push(temp->left);
//         }

//         int rightData;
//         cout << "Enter data for right of " << temp->data << " node : ";
//         cin >> rightData;

//         if (rightData != -1)
//         {
//             temp->right = new Node(rightData);
//             q.push(temp->right);
//         }
//     }
// }
// void levelOrderTraversal(Node *root)
// {
//     queue<Node *> q;
//     q.push(root);
//     q.push(nullptr);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         if (temp == nullptr)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(nullptr);
//             }
//         }
//         else
//         {
//             cout << temp->data << " ";
//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }

//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }

// // Balanced Binary Tree
// pair<bool, int> BalancedTree(Node *root)
// {
//     // Base case
//     if (root == nullptr)
//     {
//         pair<bool, int> p = make_pair(true, 0);
//         return p;
//     }

//     // Recursive Calls
//     pair<bool, int> left = BalancedTree(root->left);
//     pair<bool, int> right = BalancedTree(root->right);

//     bool op1 = left.first;
//     bool op2 = right.first;
//     bool diff = abs(left.second - right.second) <= 1;

//     pair<bool, int> ans;
//     ans.second = max(left.second, right.second) + 1;
//     if (op1 && op2 && diff)
//     {
//         ans.first = true;
//     }
//     else
//     {
//         ans.first = false;
//     }

//     return ans;
// }
// // Identical Tree check
// bool IndenticalOrCompareBinaryTree(Node *a, Node *b)
// {
//     if (a == NULL && b == NULL)
//         return 1;

//     /* 2. both non-empty -> compare them */
//     if (a != NULL && b != NULL)
//     {
//         return (a->data == b->data && IndenticalOrCompareBinaryTree(a->left, b->left) && IndenticalOrCompareBinaryTree(a->right, b->right));
//     }

//     /* 3. one empty, one not -> false */
//     return 0;
// }
// pair<bool, int> SumTree(Node *root)
// {
//     // Base Case
//     if (root == nullptr)
//     {
//         pair<bool, int> p = make_pair(true, 0);
//         return p;
//     }
//     if (root->left == nullptr && root->right == nullptr)
//     {
//         pair<bool, int> p = make_pair(true, root->data);
//         return p;
//     }

//     pair<bool, int> left = SumTree(root->left);
//     pair<bool, int> right = SumTree(root->right);

//     bool leftFirst = left.first;
//     bool rightFirst = right.first;
//     bool condition = root->data == (left.second + right.second);

//     pair<bool, int> ans;
//     if (leftFirst && rightFirst && condition)
//     {
//         ans.first = true;
//         ans.second = root->data + left.second + right.second;
//     }
//     else
//     {
//         ans.first = false;
//     }

//     return ans;
// }
// int main()
// {
//     Node *root = nullptr;

//     // InsertNode(root);

//     // levelOrderTraversal(root);

//     // cout << BalancedTree(root).first << endl;

//     Node *root1 = nullptr;
//     Node *root2 = nullptr;
//     // InsertNode(root1);
//     // InsertNode(root2);

//     // bool ans = IndenticalOrCompareBinaryTree(root1, root2);
//     // cout << ans << endl;

//     Node *root3 = nullptr;
//     InsertNode(root3);
//     cout << SumTree(root3).first << endl;

//     return 0;
// }

// 15 Feb 2024  ( Night )
#include <iostream>
#include <queue>
#include <stack>
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

    cout << "Reverse Order Traversal : ";
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}
void LeafNodeCount(Node *root, int &count)
{
    // Base Case
    if (root == nullptr)
    {
        return;
    }

    LeafNodeCount(root->left, count);
    if (root->left == nullptr && root->right == nullptr)
    {
        count++;
    }
    LeafNodeCount(root->right, count);
}
int HeightofBinaryTree(Node *root, int depth)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = HeightofBinaryTree(root->left, depth);
    int right = HeightofBinaryTree(root->right, depth);

    depth = max(left, right) + 1;
    return depth;
}
pair<int, int> widthBinaryTree(Node *root)
{
    // Base Case
    if (root == nullptr)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = widthBinaryTree(root->left);
    pair<int, int> right = widthBinaryTree(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
pair<bool, int> BalancedTree(Node *root)
{
    // Base Case
    if (root == nullptr)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = BalancedTree(root->left);
    pair<bool, int> right = BalancedTree(root->right);

    bool op1 = left.first;
    bool op2 = right.first;
    bool op3 = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    if (op1 && op2 && op3)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}
pair<bool, int> SumTree(Node *root)
{
    // Base Case
    if (root == nullptr)
    {
        pair<int, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        pair<int, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = SumTree(root->left);
    pair<bool, int> right = SumTree(root->right);

    bool op1 = left.first;
    bool op2 = right.first;
    bool op3 = root->data == (left.second + right.second);

    pair<bool, int> ans;
    if (op1 && op2 && op3)
    {
        ans.first = true;
        ans.second = root->data + left.second + right.second;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}
bool IsIdenticalTree(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return 1;
    }

    if (root1 != nullptr && root2 != nullptr)
    {
        return (root1->data == root2->data && IsIdenticalTree(root1->left, root2->left) && IsIdenticalTree(root1->right, root2->right));
    }

    return 0;
}
int main()
{
    Node *root = nullptr;
    InsertNode(root);
    ReverseOrderTraversal(root);
    int count = 0;
    LeafNodeCount(root, count);
    cout << "Leaf Node : " << count << endl;
    int depth = 0;
    cout << "Depth Of Binary Tree : " << HeightofBinaryTree(root, depth) << endl;
    cout << "width of Binary Tree : " << widthBinaryTree(root).first << endl;
    cout << "Checking Balanced Binary Tree or not : " << BalancedTree(root).first << endl;
    cout << "Checking Sum tree or not : " << SumTree(root).first << endl;

    Node *root1 = nullptr;
    Node *root2 = nullptr;
    InsertNode(root1);
    InsertNode(root2);

    cout << "Checking Whether the two tree is identical or not : " << IsIdenticalTree(root1, root2) << endl;
    return 0;
}