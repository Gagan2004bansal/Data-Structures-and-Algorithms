#include <iostream>
#include <vector>
using namespace std;
int SolveUsingRec(int n)
{
    // Base Case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    // Recursive Relation
    int ans = (n - 1) * (SolveUsingRec(n - 1) + SolveUsingRec(n - 2));

    // Return ans
    return ans;
}
int SolveUsingMemo(int n, vector<int> &dp)
{
    // Base Case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Recursive Relation
    dp[n] = (n - 1) * (SolveUsingMemo(n - 1, dp) + SolveUsingMemo(n - 2, dp));

    // Return ans
    return dp[n];
}
int SolveUsingTabu(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        int first = dp[i - 1];
        int second = dp[i - 2];
        int sum = (first + second);

        int ans = (i - 1) * sum;
        dp[i] = ans;
    }

    return dp[n];
}
int SolveUsingTabuSO(int n)
{
    int prev2 = 0;
    int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        int first = prev1;
        int second = prev2;

        int sum = (prev1 + prev2);
        int ans = (i - 1) * sum;

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}
int main()
{
    int n;
    cin >> n;

    cout << "Solve using Recursion : ";
    cout << SolveUsingRec(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Solve using Recursion + Memoisation : ";
    cout << SolveUsingMemo(n, dp) << endl;

    cout << "Solve using Tabulation : ";
    cout << SolveUsingTabu(n) << endl;

    cout << "Solve using Tabulation + Space Optimize : ";
    cout << SolveUsingTabuSO(n) << endl;
    return 0;
}