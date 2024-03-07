#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void InsertAtHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        int data;
        cout << "Enter data : ";
        cin >> data;
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        int data;
        cout << "Enter data : ";
        cin >> data;
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}
void InsertAtTail(Node *&tail, Node *&head)
{
    if (tail == NULL)
    {
        int data;
        cout << "Enter data : ";
        cin >> data;
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        int data;
        cout << "Enter data : ";
        cin >> data;
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}
void InsertAtPosition(Node *&head, Node *&tail)
{
    int position;
    cout << "Enter position you want to insert element : ";
    cin >> position;

    if (position == 0)
    {
        InsertAtHead(head, tail);
        return;
    }
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    if (position == length)
    {
        InsertAtTail(tail, head);
        return;
    }

    int data;
    cout << "Enter data : ";
    cin >> data;

    Node *newNode = new Node(data);
    temp = head;
    for (int i = 1; i < position; ++i)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *root = NULL;
    Node *head = root;
    Node *tail = root;
    InsertAtHead(head, tail);
    InsertAtHead(head, tail);
    InsertAtPosition(head, tail);
    InsertAtTail(tail, head);
    InsertAtHead(head, tail);
    display(head);
    deleteNode(1, head);
    display(head);
    return 0;
}