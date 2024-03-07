// link : https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// #include <iostream>
// #include <vector>
// using namespace std;
// int SolveUsingRec(int n, vector<int> &nums)
// {
//     // Base Case
//     if (n == 0)
//     {
//         return 0;
//     }

//     int left = SolveUsingRec(n - 1, nums) + abs(nums[n] - nums[n - 1]);
//     int right = INT_MAX;

//     if (n > 1)
//     {
//         right = SolveUsingRec(n - 2, nums) + abs(nums[n] - nums[n - 2]);
//     }

//     int ans = min(left, right);
//     return ans;
// }
// int SolveUsingMemo(int n, vector<int> &nums, vector<int> &dp)
// {
//     // Base Condition
//     if (n == 0)
//     {
//         return 0;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     int left = SolveUsingMemo(n - 1, nums, dp) + abs(nums[n] - nums[n - 1]);
//     int right = INT_MAX;

//     if (right > 1)
//     {
//         right = SolveUsingMemo(n - 2, nums, dp) + abs(nums[n] - nums[n - 2]);
//     }

//     dp[n] = min(left, right);
//     return dp[n];
// }
// int solveUsingTabu(int n, vector<int> &nums)
// {
//     vector<int> dp(n, -1);
//     dp[0] = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         int left = dp[i - 1] + abs(nums[i] - nums[i - 1]);
//         int right = INT_MAX;
//         if (i > 1)
//         {
//             right = dp[i - 2] + abs(nums[i] - nums[i - 2]);
//         }

//         dp[i] = min(left, right);
//     }

//     return dp[n];
// }
// int SolveUsingTabuSO(int n, vector<int> nums)
// {
//     int prev2 = 0;
//     int prev1 = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         int left = prev1 + abs(nums[i] - nums[i - 1]);
//         int right = INT_MAX;
//         if (i > 1)
//         {
//             right = prev2 + abs(nums[i] - nums[i - 2]);
//         }

//         int ans = min(left, right);

//         prev2 = prev1;
//         prev1 = ans;
//     }
//     return prev1;
// }
// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> nums;
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         nums.push_back(input);
//     }

//     cout << SolveUsingRec(n - 1, nums) << endl;

//     vector<int> dp(n, -1);
//     cout << SolveUsingMemo(n - 1, nums, dp) << endl;

//     cout << solveUsingTabu(n - 1, nums) << endl;

//     cout << SolveUsingTabuSO(n - 1, nums) << endl;

//     return 0;
// }

// Follow up same question if there frog can k jump not 1 and 2 how you solve that approach
#include <iostream>
#include <vector>
using namespace std;
int SolveUsingRecMemo(int n, int k, vector<int> &nums, vector<int> &dp)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int left = SolveUsingRecMemo(n - i, k, nums, dp) + abs(nums[n] - nums[n - i]);

            ans = min(left, ans);
        }
    }

    dp[n] = ans;
    return dp[n];
}
int solveUsingTabu(int n, vector<int> &nums, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int ans = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int left = dp[i - j] + abs(nums[i] - nums[i - j]);
                ans = min(left, ans);
            }
        }

        dp[i] = ans;
    }

    return dp[n - 1];
}
int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    int k;
    cin >> k;
    vector<int> dp(n, -1);
    cout << SolveUsingRecMemo(n - 1, k, nums, dp) << endl;

    cout << solveUsingTabu(n, nums, k) << endl;

    return 0;
}