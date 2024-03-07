// CLONE A LINKED LISTS WITH RANDOM POINTER
// HARD QUESTION OF LINKED LISTS

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};
void insertAthead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void insertAttail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        tail = newNode;
        head = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAthead(head, tail, data);
        return;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (position == count)
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
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void DisplayRandom(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        if (temp->random != NULL)
        {
            cout << "Value of temp random value : " << temp->random->data;
        }
        else
        {
            cout << "Value of temp random value : NULL";
        }
        temp = temp->next;
        cout << endl;
    }
}
Node *CloneLinkedList(Node *head)
{
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        insertAttail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {

        if (originalNode->random != NULL)
        {
            cloneNode->random = originalNode->random->next;
        }
        else
        {
            cloneNode->random = NULL;
        }

        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }

    Node *original = head;
    Node *copy = cloneHead;

    while (original && copy)
    {
        original->next =
            original->next ? original->next->next : original->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return cloneHead;
}
int main()
{
    Node *root = NULL;
    Node *head = root;
    Node *tail = root;

    insertAttail(head, tail, 5);
    insertAthead(head, tail, 8);
    insertAthead(head, tail, 4);
    insertAttail(head, tail, 6);
    insertAtPosition(head, tail, 7, 2);
    Display(head);

    // Pointing the random linked list within the linked list
    head->random = head->next->next;
    head->next->random = head->next->next->next;

    cout << endl;
    Node *temp = CloneLinkedList(head);
    DisplayRandom(temp);
    return 0;
}