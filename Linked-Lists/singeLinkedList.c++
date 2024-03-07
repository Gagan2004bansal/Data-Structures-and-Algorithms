#include <iostream>
#include <map>
#include <unordered_map>
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
void isCircularLinkedLists(Node *head)
{
    if (head == NULL)
    {
        cout << "Circular Linked List" << endl;
        return;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        cout << "Circular Linked List" << endl;
        return;
    }

    cout << "Not a Circular Linked List" << endl;
    return;
}
bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}
Node *floydDetectionLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}
Node *StartingNodeofLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *intersection = floydDetectionLoop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
void RemoveLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *StartOfLoop = StartingNodeofLoop(head);
    Node *temp = StartOfLoop;

    while (temp->next != StartOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return;
}

Node *ReverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *current = head;
    Node *forward = NULL;

    while (current != NULL)
    {
        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    return prev;
}
Node *Middle1(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    int i = 0;
    while (i < length / 2)
    {
        head = head->next;
        i++;
    }
    return head;
}
Node *Middle2(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node *ReverseListinKGroup(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *forw = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;

    while (count < k && curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;

        count++;
    }

    if (forw != NULL)
    {
        head->next = ReverseListinKGroup(forw, k);
    }

    return prev;
}
Node *RemoveDuplicate(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            Node *next_next = temp->next->next;
            Node *toDelete = temp->next;
            delete (toDelete);
            temp->next = next_next;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}
Node *RemoveDuplicateFromUnsortedList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    unordered_map<int, bool> visited;
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr)
    {
        if (visited[curr->data])
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
// Sort 0s 1s & 2s using count
Node *Sort0s1s2s(Node *head)
{
    int ZeroCount = 0, OneCount = 0, TwoCount = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        int value = temp->data;
        if (value == 0)
        {
            ZeroCount++;
        }
        else if (value == 1)
        {
            OneCount++;
        }
        else if (value == 2)
        {
            TwoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (ZeroCount > 0)
        {
            temp->data = 0;
            ZeroCount--;
        }
        else if (OneCount > 0)
        {
            temp->data = 1;
            OneCount--;
        }
        else if (TwoCount > 0)
        {
            temp->data = 2;
            TwoCount--;
        }
        temp = temp->next;
    }

    return head;
}
// Sort 0s 1s & 2s without Changing Data
void TailInsert(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
Node *Sort0s1s2sData(Node *head)
{
    Node *ZeroHead = new Node(-1);
    Node *Zerotail = ZeroHead;
    Node *OneHead = new Node(-1);
    Node *Onetail = OneHead;
    Node *TwoHead = new Node(-1);
    Node *Twotail = TwoHead;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            TailInsert(Zerotail, curr);
        }
        else if (curr->data == 1)
        {
            TailInsert(Onetail, curr);
        }
        else if (curr->data == 2)
        {
            TailInsert(Twotail, curr);
        }

        curr = curr->next;
    }

    // Mergeing of Three Lists
    if (OneHead->next != NULL)
    {
        Zerotail->next = OneHead->next;
    }
    else
    {
        Zerotail->next = TwoHead->next;
    }

    Onetail->next = TwoHead->next;
    Twotail->next = NULL;

    head = ZeroHead->next;

    delete OneHead;
    delete ZeroHead;
    delete TwoHead;

    return head;
}
int main()
{
    Node *root = NULL;
    Node *head = root;
    Node *tail = root;
    InsertAtHead(head, tail);
    InsertAtHead(head, tail);
    // InsertAtPosition(head, tail);
    // InsertAtTail(tail, head);
    InsertAtHead(head, tail);
    InsertAtHead(head, tail);
    InsertAtHead(head, tail);
    display(head);

    // For Circular linked List check
    // tail->next = head;
    // isCircularLinkedLists(head);

    // For Deletion Check
    deleteNode(3, head);
    display(head);

    // detect loop
    // tail->next = head->next->next; // for making of loop in LL
    // bool ans = detectLoop(head);
    // cout << ans << endl;

    // Floyd Detection Loop
    // tail->next = head->next->next; // for making of loop in LL
    // Node *check = floydDetectionLoop(head);
    // cout << check->data << endl;

    // Getting Starting point of loops
    // tail->next = head->next->next; // for making of loop in LL
    // Node *ans = StartingNodeofLoop(head);
    // cout << ans->data << endl;

    // To remove loop in Linked lists
    // RemoveLoop(head);

    // For Reverse Linked List
    // Node *temp = ReverseList(head);
    // display(temp);

    // Find middle of linked list node
    // Node *temp1 = Middle1(head);
    // display(temp1);
    // Node *temp2 = Middle2(head);
    // display(temp2);

    // Reverse Linked List in K Group
    // int k;
    // cin >> k;
    // Node *temp = ReverseListinKGroup(head, k);
    // display(temp);

    // Remove Duplicate From Linked List
    // Node *temp = RemoveDuplicate(head);
    // display(temp);

    // Node *temp = RemoveDuplicateFromUnsortedList(head);
    // display(temp);

    // Sort 0s 1s 2s using count and change data
    // Node *temp = Sort0s1s2s(head);
    // display(temp);

    // Approach 2 without changing data
    // Node *temp = Sort0s1s2sData(head);
    // display(temp);

    // Merge two sorted linked lists

    return 0;
}