// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->left = nullptr;
//         this->right = nullptr;
//     }
// };
// void InsertNode(Node *&root)
// {
//     int data;
//     cout << "Enter Data for root : ";
//     cin >> data;
//     queue<Node *> q;
//     root = new Node(data);
//     q.push(root);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         int leftData;
//         cout << "Enter Data for left of " << temp->data << " Node : ";
//         cin >> leftData;
//         if (leftData != -1)
//         {
//             temp->left = new Node(leftData);
//             q.push(temp->left);
//         }

//         int rightData;
//         cout << "Enter Data for right of " << temp->data << " Node : ";
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
// void ZigZagPattern(Node *root, vector<int> &result)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     queue<Node *> q;
//     q.push(root);
//     bool leftToright = true;

//     while (!q.empty())
//     {
//         int size = q.size();
//         vector<int> ans(size);
//         for (int i = 0; i < size; i++)
//         {
//             Node *frontNode = q.front();
//             q.pop();

//             int index = leftToright ? i : size - i - 1;
//             ans[index] = frontNode->data;

//             if (frontNode->left)
//             {
//                 q.push(frontNode->left);
//             }

//             if (frontNode->right)
//             {
//                 q.push(frontNode->right);
//             }
//         }

//         leftToright = !leftToright;
//         for (auto i : ans)
//         {
//             result.push_back(i);
//         }
//     }
// }
// void LeftTree(Node *root, vector<int> &ans)
// {
//     if (root == nullptr || (root->left == nullptr && root->right == nullptr))
//     {
//         return;
//     }
//     ans.push_back(root->data);

//     if (root->left)
//     {
//         LeftTree(root->left, ans);
//     }
//     else
//     {
//         LeftTree(root->right, ans);
//     }
// }
// void LeafTree(Node *root, vector<int> &ans)
// {
//     if (root == nullptr)
//     {
//         return;
//     }

//     LeafTree(root->left, ans);

//     if (root->left == nullptr && root->right == nullptr)
//     {
//         ans.push_back(root->data);
//         return;
//     }

//     LeafTree(root->right, ans);
// }
// void RightTree(Node *root, vector<int> &ans)
// {
//     if (root == nullptr || (root->left == nullptr && root->right == nullptr))
//     {
//         return;
//     }

//     if (root->right)
//     {
//         RightTree(root->right, ans);
//     }
//     else
//     {
//         RightTree(root->left, ans);
//     }

//     ans.push_back(root->data);
// }
// void BoundaryView(Node *root)
// {
//     vector<int> ans;
//     if (root == nullptr)
//     {
//         return;
//     }
//     ans.push_back(root->data);

//     LeftTree(root->left, ans);
//     LeafTree(root, ans);
//     RightTree(root->right, ans);

//     cout << "Boundary View of Binary Tree : ";
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     Node *root = nullptr;
//     InsertNode(root);
//     levelOrderTraversal(root);

//     vector<int> result;
//     ZigZagPattern(root, result);
//     cout << "Zig Zag Pattern or Spiral Print : ";
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << " ";
//     }
//     cout << endl;

//     BoundaryView(root);

//     return 0;
// }

// 16 Feb 2024
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
void SpiralPrint(Node *root)
{
    queue<Node *> q;
    vector<int> result;
    bool leftToright = true;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int index = leftToright ? i : size - i - 1;
            ans[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        // Important Condition
        leftToright = !leftToright;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }

    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
}
void LeftTree(Node *root, vector<int> &ans)
{
    // Base Case
    if (root == NULL || (root->left == NULL || root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);

    if (root->left)
    {
        LeftTree(root->left, ans);
    }
    else
    {
        LeftTree(root->right, ans);
    }
}
void LeafTree(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    LeafTree(root->left, ans);
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(root->data);
        return;
    }
    LeafTree(root->right, ans);
}
void RightTree(Node *&root, vector<int> &ans)
{
    if (root == NULL || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }
    if (root->right)
    {
        RightTree(root->right, ans);
    }
    else
    {
        RightTree(root->left, ans);
    }

    ans.push_back(root->data);
}
void BoundaryView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    vector<int> ans;
    ans.push_back(root->data);
    // Left
    LeftTree(root->left, ans);
    // Leaf
    LeafTree(root, ans);
    // Right
    RightTree(root->right, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    Node *root = nullptr;
    InsertNode(root);
    SpiralPrint(root);
    BoundaryView(root);
    return 0;
}