// Code Studio -- https://www.codingninjas.com/studio/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <iostream>
#include <vector>
using namespace std;
int SolveWithSC(vector<int> &arr)
{
    int prev2 = 0;
    int prev1 = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        int include = prev2 + arr[i];
        int exclude = prev1 + 0;
        int ans = max(include, exclude);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    if (n == 1)
    {
        cout << arr[0] << endl;
        exit(0);
    }

    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            first.push_back(arr[i]);
        }
        if (i != 0)
        {
            second.push_back(arr[i]);
        }
    }

    cout << max(SolveWithSC(first), SolveWithSC(second)) << endl;

    return 0;
}