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
void InsertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        return;
    }
}
void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
        return;
    }
}
void InsertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        InsertAtHead(head, tail, data);
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
    for (int i = 1; i < position; i++)
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
Node *Solve(Node *first, Node *second)
{
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = first->next;
    Node *curr2 = second;
    Node *next2 = second->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}
Node *MergeTwoSortedLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data <= head2->data)
    {
        return Solve(head1, head2);
    }
    else
    {
        return Solve(head2, head1);
    }
}
int main()
{
    Node *first = NULL;
    cout << "Enter data for first ll \n";
    Node *head1 = first;
    Node *tail1 = first;

    InsertAtTail(head1, tail1, 5);
    InsertAtHead(head1, tail1, 3);
    InsertAtHead(head1, tail1, 0);
    InsertAtPosition(head1, tail1, 4, 2);

    display(head1);

    Node *second = NULL;
    cout << "Enter data for second ll \n";
    Node *head2 = second;
    Node *tail2 = second;

    InsertAtTail(head2, tail2, 7);
    InsertAtHead(head2, tail2, 2);
    InsertAtHead(head2, tail2, 1);
    InsertAtPosition(head2, tail2, 6, 2);

    display(head2);

    Node *mergeLL = MergeTwoSortedLL(head1, head2);

    cout << "After Merge Two Sorted LL" << endl;
    display(mergeLL);

    return 0;
}