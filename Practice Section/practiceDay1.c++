// #include <iostream>
// #include <queue>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// void buildfromleveltrasversal(Node *&root)
// {
//     queue<Node *> q;
//     cout << "Enter data for root : " << endl;
//     int data;
//     cin >> data;

//     root = new Node(data);

//     q.push(root);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         int leftdata;
//         cout << "Enter Data for left of " << temp->data << " left node : ";
//         cin >> leftdata;

//         if (leftdata != -1)
//         {
//             temp->left = new Node(leftdata);
//             q.push(temp->left);
//         }

//         int rightdata;
//         cout << "Enter Data for right of " << temp->data << " right node : ";
//         cin >> rightdata;

//         if (rightdata != -1)
//         {
//             temp->right = new Node(rightdata);
//             q.push(temp->right);
//         }
//     }
// }
// void levelOrdertransversal(Node *root)
// {
//     queue<Node *> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         if (temp == NULL)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {
//             cout << temp->data << " ";
//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }

//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }
// void preOrderTrasversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     cout << root->data << " ";
//     preOrderTrasversal(root->left);
//     preOrderTrasversal(root->right);
// }
// void postOrderTrasversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     postOrderTrasversal(root->left);
//     postOrderTrasversal(root->right);

//     cout << root->data << " ";
// }
// void inOrderTrasversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     inOrderTrasversal(root->left);
//     cout << root->data << " ";
//     inOrderTrasversal(root->right);
// }
// int main()
// {
//     Node *root = NULL;
//     buildfromleveltrasversal(root);
//     // levelOrdertransversal(root);
//     // preOrderTrasversal(root);
//     // postOrderTrasversal(root);
//     inOrderTrasversal(root);
//     return 0;
// }

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(std::vector<int> &temperatures)
{
    vector<int> ans(temperatures.size(), 0);
    stack<int> st;

    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int prevIndex = st.top();
            st.pop();
            ans[prevIndex] = i - prevIndex;
        }
        st.push(i);
    }

    return ans;
}

int main()
{
    vector<int> arr;
    int n = 8;

    int a;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }

    vector<int> res = dailyTemperatures(arr);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}

//  vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> ans;
//         stack<int> st;
//         stack<int> st1;
//         ans.push_back(0);

//         int e = temperatures.size() - 1;
//         st.push(temperatures[e]);

//         for (int i = e - 1; i >= 0; i--) {
//             if (temperatures[i] < st.top()) {
//                 ans.push_back(1);
//                 st.push(temperatures[i]);
//             } else {
//                 int count = 1;
//                 bool check = true;
//                 while (!st.empty()) {
//                     if (st.top() > temperatures[i]) {
//                         ans.push_back(count);
//                         st.push(temperatures[i]);
//                         check = false;
//                         break;
//                     } else {
//                         count++;
//                         st1.push(st.top());
//                         st.pop();
//                     }
//                 }
//                 while (!st1.empty()) {
//                     st.push(st1.top());
//                     st1.pop();
//                 }

//                 if (check) {
//                     ans.push_back(0);
//                     st.push(temperatures[i]);
//                 }
//                 else{
//                     ans.push_back(count);
//                     st.push(temperatures[i]);
//                 }
//             }
//         }

//         reverse(ans.begin(), ans.end());

//         return ans;
//     }