// Binary Tree DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

// Morris Traversal PreOrder
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
        cout << "Enter data for left " << temp->data << " Node : ";
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for right " << temp->data << " Node : ";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
void MorrisPreOrder(Node *root)
{
    while (root)
    {
        if (root->left == NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
        else
        {
            Node *curr = root->left;
            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }

            if (curr->right == root)
            {
                curr->right = NULL;
                root = root->right;
            }
            else
            {
                cout << root->data << " ";
                curr->right = root;
                root = root->left;
            }
        }
    }
}
int main()
{
    Node *root = NULL;
    InsertNode(root);
    MorrisPreOrder(root);
    cout << endl;
    return 0;
}