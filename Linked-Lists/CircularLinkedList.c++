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

void insertAttail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        tail->next = head;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        tail->next = temp;
        tail = temp;
    }
}

void insertAthead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        tail->next = head;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        tail->next = head;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAthead(head, tail, data);
        return;
    }
    int count = 0;
    Node *temp = head;
    do
    {
        temp = temp->next;
        count++;
    } while (temp != head);

    if (temp->next == head)
    {
        insertAttail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    temp = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void Display(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main()
{
    Node *root = NULL;
    Node *head = root;
    Node *tail = root;

    insertAthead(head, tail, 1);
    insertAthead(head, tail, 2);
    insertAthead(head, tail, 3);
    insertAthead(head, tail, 4);
    insertAthead(head, tail, 5);

    insertAtPosition(head, tail, 3, 6);

    Display(head);

    return 0;
}
