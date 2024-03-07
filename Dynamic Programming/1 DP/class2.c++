// Dynamic Programming DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META
// Ques 1.   House Robbing problem
#include <iostream>
#include <vector>
using namespace std;
int solveUsingRecursion(vector<int> &arr, int index) // T.C  => exponetial   S.C ==> O(N)
{
    // Base Case
    if (index >= arr.size())
    {
        return 0;
    }

    // recursive relation
    int include = arr[index] + solveUsingRecursion(arr, index + 2);
    int exculde = 0 + solveUsingRecursion(arr, index + 1);

    int ans = max(include, exculde);
    return ans;
}
int solveusingMemoisation(vector<int> &arr, int index, vector<int> &dp) // T.C ==> O(N) S.C ==> O(N)
{
    // Base case
    if (index >= arr.size())
    {
        return 0;
    }

    // step 1 : check it is already stored or not
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int include = arr[index] + solveusingMemoisation(arr, index + 2, dp);
    int exculde = 0 + solveusingMemoisation(arr, index + 1, dp);
    dp[index] = max(include, exculde);
    return dp[index];
}
int solveusingTabulation(vector<int> &arr) // T.C ==> O(N)  S.C ==> O(N)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    dp[n - 1] = arr[n - 1];

    for (int index = n - 2; index >= 0; index--)
    {
        int tempAns = 0;
        if (index + 2 < n)
        {
            tempAns = dp[index + 2];
        }
        int include = arr[index] + tempAns;
        int exculde = 0 + dp[index + 1];
        dp[index] = max(include, exculde);
    }

    return dp[0];
}
int solveusingTabulationOpt(vector<int> &arr) // T.C ==> O(N)  S.C ==> (1)
{
    int n = arr.size();
    int next = 0, curr = 0, prev = arr[n - 1];

    for (int index = n - 2; index >= 0; index--)
    {
        int tempAns = 0;
        if (index + 2 <)
        {
            tempAns = next;
        }

        int include = arr[index] + tempAns;
        int exculde = 0 + prev;

        curr = max(include, exculde);

        // Important
        next = prev;
        prev = curr;
    }

    return prev;
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

    int index = 0;
    cout << solveUsingRecursion(arr, index) << endl;

    // vector<int> dp(n, -1);
    // cout << solveusingMemoisation(arr, index, dp) << endl;

    // cout << solveusingTabulation(arr) << endl;

    cout << solveusingTabulationOpt(arr) << endl;

    return 0;
}