// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

// Construct Binary tree from Inorder and PostOrder
// #include <iostream>
// #include <vector>
// #include <queue>
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
// int position(vector<int> Inorder, int element, int InorderStart, int InorderEnd)
// {
//     for (int i = InorderStart; i <= InorderEnd; i++)
//     {
//         if (Inorder[i] == element)
//         {
//             return i;
//         }
//     }

//     return -1;
// }
// Node *Solve(vector<int> &Inorder, vector<int> &PostOrder, int &PostOrderIndex, int n, int InorderStart, int InorderEnd)
// {
//     // Base Case
//     if (PostOrderIndex < 0 || InorderStart > InorderEnd)
//     {
//         return nullptr;
//     }

//     int element = PostOrder[PostOrderIndex];
//     Node *root = new Node(element);
//     int pos = position(Inorder, element, InorderStart, InorderEnd);
//     PostOrderIndex--;

//     root->right = Solve(Inorder, PostOrder, PostOrderIndex, n, pos + 1, InorderEnd);
//     root->left = Solve(Inorder, PostOrder, PostOrderIndex, n, InorderStart, pos - 1);

//     return root;
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

//         if (temp == NULL)
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

// void PreOrderTraversal(Node *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }

//     cout << root->data << " ";

//     PreOrderTraversal(root->left);
//     PreOrderTraversal(root->right);
// }
// int main()
// {
//     vector<int> Inorder;
//     vector<int> PostOrder;

//     int n;
//     cin >> n;
//     cout << "Inorder : ";
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         Inorder.push_back(input);
//     }

//     cout << "Postorder : ";
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         PostOrder.push_back(input);
//     }

//     int PostOrderIndex = n - 1;
//     int InorderStart = 0;
//     int InorderEnd = n - 1;

//     Node *ans = Solve(Inorder, PostOrder, PostOrderIndex, n, InorderStart, InorderEnd);
//     levelOrderTraversal(ans);
//     // PreOrderTraversal(ans);
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <queue>
#include <map>
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
    cout << "Enter data for the root node : ";
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
Node *MapParentNode(int target, Node *root, map<Node *, Node *> &ParentMap)
{
    Node *res = NULL;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->data == target)
        {
            res = temp;
        }

        if (temp->left)
        {
            q.push(temp->left);
            ParentMap[temp->left] = temp;
        }

        if (temp->right)
        {
            q.push(temp->right);
            ParentMap[temp->right] = temp;
        }
    }

    return res;
}
int BurningTree(Node *targetNode, map<Node *, Node *> ParentMap)
{
    map<Node *, bool> visited;
    visited[targetNode] = true;
    int ans = 0;

    queue<Node *> q;
    q.push(targetNode);

    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
                flag = 1;
            }

            if (temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
                flag = 1;
            }

            if (ParentMap[temp] && !visited[ParentMap[temp]])
            {
                q.push(ParentMap[temp]);
                visited[ParentMap[temp]] = true;
                flag = 1;
            }
        }

        if (flag)
        {
            ans++;
        }
    }

    return ans;
}
int MinTimeToBurnTree(Node *root, int target)
{
    map<Node *, Node *> ParentMap;
    Node *targetNode = MapParentNode(target, root, ParentMap);

    int ans = BurningTree(targetNode, ParentMap);

    return ans;
}
int main()
{
    Node *root = nullptr;
    InsertNode(root);
    int target;
    cin >> target;

    int result = MinTimeToBurnTree(root, target);
    cout << result << endl;
    return 0;
}