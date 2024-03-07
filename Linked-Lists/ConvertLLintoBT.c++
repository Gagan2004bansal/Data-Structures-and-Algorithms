#include <iostream>
#include <queue>
using namespace std;
class LLNode
{
public:
    int data;
    LLNode *next;
    LLNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
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
void InsertAtHead(LLNode *&head, LLNode *&tail, int data)
{
    LLNode *temp = new LLNode(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void InsertAtTail(LLNode *&head, LLNode *&tail, int data)
{
    LLNode *temp = new LLNode(data);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void InsertAtPos(LLNode *&head, LLNode *&tail, int data, int pos)
{
    if (pos == 0)
    {
        InsertAtHead(head, tail, data);
        return;
    }

    int length = 0;
    LLNode *temp = head;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }

    if (length == pos)
    {
        InsertAtTail(head, tail, data);
        return;
    }

    temp = head;
    int i = 1;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }

    LLNode *newNode = new LLNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}
void Display(LLNode *head)
{
    LLNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
void ConvertLLtoBT(LLNode *head, Node *&BinaryTreeRoot)
{
    queue<Node *> q;
    if (head == NULL)
    {
        BinaryTreeRoot = NULL;
        return;
    }

    BinaryTreeRoot = new Node(head->data);
    q.push(BinaryTreeRoot);

    head = head->next;

    while (head)
    {
        Node *parent = q.front();
        q.pop();

        Node *leftChild = NULL, *rightChild = NULL;

        leftChild = new Node(head->data);
        q.push(leftChild);
        head = head->next;
        if (head)
        {
            rightChild = new Node(head->data);
            q.push(rightChild);
            head = head->next;
        }

        parent->left = leftChild;
        parent->right = rightChild;
    }
}
void InorderTraversal(Node *BinaryTreeRoot)
{
    if (BinaryTreeRoot == nullptr)
    {
        return;
    }

    InorderTraversal(BinaryTreeRoot->left);
    cout << BinaryTreeRoot->data << " ";
    InorderTraversal(BinaryTreeRoot->right);
}
int main()
{
    LLNode *root = NULL;
    LLNode *head = root;
    LLNode *tail = root;

    InsertAtHead(head, tail, 3);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 1);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 5);
    InsertAtPos(head, tail, 6, 5);

    Display(head);

    Node *BinaryTreeRoot = NULL;
    ConvertLLtoBT(head, BinaryTreeRoot);

    cout << "Inorder Traversal : ";
    InorderTraversal(BinaryTreeRoot);
    cout << endl;
    return 0;
}