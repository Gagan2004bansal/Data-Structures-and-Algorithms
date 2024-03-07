#include <iostream>
#include <vector>
using namespace std;
int solveUsingRecursion(vector<int> &coins, int amount)
{
    // Base Case
    if (amount == 0)
    {
        return 0;
    }
    // Recursive Relation
    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        if (amount - coins[i] >= 0)
        {
            int answer = solveUsingRecursion(coins, amount - coins[i]);
            if (answer != INT_MAX)
            {
                int ans = 1 + answer;
                mini = min(mini, ans);
            }
        }
    }
    return mini;
}
int solveUsingMemo(vector<int> &coins, int amount, vector<int> &dp)
{
    // Base Case
    if (amount == 0)
    {
        return 0;
    }
    // jo phle hm evaluate kr chuke h usse store kr lege
    if (dp[amount] != -1)
    {
        return dp[amount];
    }

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (amount - coins[i] >= 0)
        {
            int answer = solveUsingMemo(coins, amount - coins[i], dp);
            if (answer != INT_MAX)
            {
                int ans = 1 + answer;
                mini = min(mini, ans);
            }
        }
    }
    dp[amount] = mini;
    return dp[amount];
}
int solveUsingTabulation(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;

    for (int value = 1; value <= amount; value++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (value - coins[i] >= 0)
            {
                int answer = dp[value - coins[i]];
                if (answer != INT_MAX)
                {
                    int ans = 1 + answer;
                    mini = min(mini, ans);
                }
            }
        }

        dp[value] = mini;
    }

    return dp[amount];
}
int main()
{
    int n;
    cin >> n;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        coins.push_back(input);
    }

    int amount;
    cin >> amount;

    // int ans = solveUsingRecursion(coins, amount);

    // if (ans == INT_MAX)
    // {
    //     cout << -1 << endl;
    // }
    // else
    // {
    //     cout << ans << endl;
    // }

    vector<int> dp(amount + 1, -1);
    int ans = solveUsingMemo(coins, amount, dp);
    cout << ans << endl;

    // cout << solveUsingTabulation(coins, amount) << endl;

    return 0;
}