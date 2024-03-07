#include <iostream>
#include <vector>
#include <queue>
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
class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
Node *Solution(vector<Node *> &arr)
{
    int k = arr.size();

    if (k == 0)
    {
        return NULL;
    }

    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] != NULL)
        {
            pq.push(arr[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (pq.size() > 0)
    {
        Node *temp = pq.top();
        pq.pop();

        if (temp->next)
        {
            pq.push(temp->next);
        }

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }

    return head;
}
int main()
{
    Node *root1 = NULL;
    Node *head = root1;
    Node *tail = root1;
    InsertAtHead(head, tail, 5);
    InsertAtHead(head, tail, 4);
    InsertAtHead(head, tail, 1);

    Node *root2 = NULL;
    Node *head1 = root2;
    Node *tail1 = root2;
    InsertAtHead(head1, tail1, 4);
    InsertAtHead(head1, tail1, 3);
    InsertAtHead(head1, tail1, 1);

    Node *root3 = NULL;
    Node *head2 = root3;
    Node *tail2 = root3;
    InsertAtHead(head2, tail2, 6);
    InsertAtHead(head2, tail2, 2);

    vector<Node *> arr;
    arr.push_back(head);
    arr.push_back(head1);
    arr.push_back(head2);

    Node *ans = Solution(arr);
    display(ans);

    return 0;
}