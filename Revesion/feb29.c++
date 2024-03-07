// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

// Morris Traversal Inorder
// #include <iostream>
// #include <queue>
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
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// void InsertNode(Node *&root)
// {
//     int data;
//     cout << "Enter data for root : ";
//     cin >> data;

//     if (data == -1)
//     {
//         return;
//     }

//     root = new Node(data);
//     queue<Node *> q;
//     q.push(root);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         int leftData;
//         cout << "Enter Data for left of " << temp->data << " node : ";
//         cin >> leftData;
//         if (leftData != -1)
//         {
//             temp->left = new Node(leftData);
//             q.push(temp->left);
//         }

//         int rightData;
//         cout << "Enter Data for right of " << temp->data << " node : ";
//         cin >> rightData;
//         if (rightData != -1)
//         {
//             temp->right = new Node(rightData);
//             q.push(temp->right);
//         }
//     }
// }
// void MorrisInorderTraversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     Node *curr, *pred;
//     curr = root;

//     while (curr != NULL)
//     {
//         if (curr->left == NULL)
//         {
//             cout << curr->data << " ";
//             curr = curr->right;
//         }
//         else
//         {
//             pred = curr->left;
//             while (pred->right != NULL && pred->right != curr)
//             {
//                 pred = pred->right;
//             }

//             if (pred->right == NULL)
//             {
//                 pred->right = curr;
//                 curr = curr->left;
//             }
//             else
//             {
//                 pred->right = NULL;
//                 cout << curr->data << " ";
//                 curr = curr->right;
//             }
//         }
//     }
// }
// int main()
// {
//     Node *root = NULL;
//     InsertNode(root);

//     MorrisInorderTraversal(root);
//     cout << endl;
//     return 0;
// }

// ODD EVEN TREE
// link : https://leetcode.com/problems/even-odd-tree/?envType=daily-question&envId=2024-02-29
#include <iostream>
#include <queue>
#include <limits.h>
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
        cout << "Enter Data for left of " << temp->data << " node : ";
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter Data for right of " << temp->data << " node : ";
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
bool OddEvenTree(Node *root)
{
    if (root->data % 2 == 0)
    {
        return false;
    }

    queue<Node *> q;
    q.push(root);
    bool LeftToRight = true;

    while (!q.empty())
    {
        int prevVal = LeftToRight ? INT_MIN : INT_MAX;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int currVal = temp->data;

            if ((LeftToRight && (currVal % 2 == 0 || currVal <= prevVal)) || (!LeftToRight && (currVal % 2 != 0 || currVal >= prevVal)))
            {
                return false;
            }

            prevVal = currVal;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        LeftToRight = !LeftToRight;
    }

    return true;
}
int main()
{
    Node *root = NULL;
    InsertNode(root);
    bool ans = OddEvenTree(root);
    cout << ans << endl;
    return 0;
}