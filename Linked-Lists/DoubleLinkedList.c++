#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void InsertAtHead(Node *&head, Node *&tail)
{
    int data;
    cout << "Enter Data : ";
    cin >> data;

    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    return;
}
void InsertAtTail(Node *&head, Node *&tail)
{
    int data;
    cout << "Enter Data : ";
    cin >> data;

    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    return;
}
void InsertAtPosition(Node *&head, Node *&tail)
{
    int position;
    cout << "Enter Position : ";
    cin >> position;
    if (position == 1)
    {
        InsertAtHead(head, tail);
        return;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    if (cnt == position)
    {
        InsertAtTail(head, tail);
        return;
    }

    int data;
    cout << "Enter Data : ";
    cin >> data;

    Node *newNode = new Node(data);
    temp = head;

    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;

    return;
}
void display(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
void DeleteNode(Node *&head)
{
    int position;
    cout << "Enter Position to delete Node : ";
    cin >> position;

    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next;
        delete (temp);
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

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }

    return;
}
int main()
{
    Node *root = NULL;
    Node *head = root;
    Node *tail = root;
    InsertAtHead(head, tail);
    InsertAtHead(head, tail);
    InsertAtHead(head, tail);
    InsertAtHead(head, tail);
    InsertAtTail(head, tail);
    InsertAtTail(head, tail);
    InsertAtTail(head, tail);
    InsertAtTail(head, tail);

    InsertAtPosition(head, tail);
    display(head, tail);

    return 0;
}