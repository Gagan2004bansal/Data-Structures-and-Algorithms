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
    Node *temp = new Node(data);
    if (head == NULL || tail == NULL)
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
    if (head == NULL || tail == NULL)
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
void InsertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 0)
    {
        InsertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 0;
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

    temp = head;
    Node *newNode = new Node(data);

    int i = 1;
    while (i < position)
    {
        temp = temp->next;
        i++;
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

    cout << endl;
}
Node *Mid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node *Merge(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            temp->next = first;
            temp = first;
            first = first->next;
        }
        else
        {
            temp->next = second;
            temp = second;
            second = second->next;
        }
    }

    while (first != NULL)
    {
        temp->next = first;
        temp = first;
        first = first->next;
    }

    while (second != NULL)
    {
        temp->next = second;
        temp = second;
        second = second->next;
    }

    ans = ans->next;
    return ans;
}
Node *MergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = Mid(head);

    Node *left = head;
    Node *right = mid->next;

    mid->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);

    Node *result = Merge(left, right);

    return result;
}
int main()
{
    Node *root = NULL;
    Node *head = root;
    Node *tail = root;

    InsertAtTail(head, tail, 5);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, 1);

    InsertAtPosition(head, tail, 0, 0);
    InsertAtPosition(head, tail, 6, 6);
    // InsertAtPosition(head, tail, 7, 3);

    Display(head);

    Node *ans = MergeSort(head);

    Display(ans);

    return 0;
}