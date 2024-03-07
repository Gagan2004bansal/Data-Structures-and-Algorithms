#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAthead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
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
void InsertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
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
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 0)
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
        InsertAtTail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    temp = head;
    for (int i = 1; i < position; ++i)
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
Node *Reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forw = NULL;

    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

Node *Add(Node *first, Node *second)
{
    int carry = 0;

    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }

        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        InsertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        if (first != NULL)
        {
            first = first->next;
        }

        if (second != NULL)
        {
            second = second->next;
        }
    }

    return ansHead;
}

Node *addTwoLists(Node *first, Node *second)
{
    first = Reverse(first);
    second = Reverse(second);

    Node *ans = Add(first, second);

    ans = Reverse(ans);

    return ans;
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
    InsertAtTail(head, tail, 0);
    insertAtPosition(head, tail, 45, 4);

    Display(head);
    cout << endl;

    Node *root1 = NULL;
    Node *head1 = root1;
    Node *tail1 = root1;
    insertAthead(head1, tail1, 6);
    insertAthead(head1, tail1, 8);
    insertAthead(head1, tail1, 7);
    insertAthead(head1, tail1, 9);
    insertAthead(head1, tail1, 10);
    InsertAtTail(head1, tail1, 11);
    insertAtPosition(head1, tail1, 35, 4);

    Display(head1);
    cout << endl;

    Node *first = head;
    Node *second = head1;

    Node *result = addTwoLists(first, second);

    Display(result);
    return 0;
}