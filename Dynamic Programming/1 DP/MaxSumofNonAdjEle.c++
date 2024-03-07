// Maximum sum of non-adajcent element in an array
// CodeStudio --  https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include <iostream>
#include <vector>
using namespace std;
int SolveUsingRec(int n, vector<int> &arr) // This Soln gives TLE as it uses exponetial time
{
    // Base Case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }
    // Recursive Relation
    int incl = SolveUsingRec(n - 2, arr) + arr[n];
    int excl = SolveUsingRec(n - 1, arr) + 0;
    // Return ans
    return max(incl, excl);
}
int SolveUsingMemo(int n, vector<int> &arr, vector<int> &dp)
{
    // Base Case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    // Recursive Relation
    int incl = SolveUsingMemo(n - 2, arr, dp) + arr[n];
    int excl = SolveUsingMemo(n - 1, arr, dp) + 0;
    // Return ans
    dp[n] = max(incl, excl);
    return dp[n];
}
int SolveUsingTabu(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int incl = dp[i - 2] + arr[i];
        int excl = dp[i - 1] + 0;

        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}
int SolveUsingTabuSC(vector<int> &arr)
{
    int n = arr.size();
    int prev2 = 0;
    int prev1 = arr[0];

    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + arr[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);
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

    cout << SolveUsingRec(n - 1, arr) << endl;

    vector<int> dp(n, 0);
    cout << SolveUsingMemo(n - 1, arr, dp) << endl;

    cout << SolveUsingTabu(arr) << endl;

    cout << SolveUsingTabuSC(arr) << endl;

    return 0;
}