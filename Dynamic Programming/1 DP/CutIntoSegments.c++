// Cut into Segment
// CodeStudio -- https://www.codingninjas.com/studio/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int SolveUsingRec(int n, int x, int y, int z)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    // Recursive Realtion
    int a = SolveUsingRec(n - x, x, y, z) + 1;
    int b = SolveUsingRec(n - y, x, y, z) + 1;
    int c = SolveUsingRec(n - z, x, y, z) + 1;

    int ans = max(a, max(b, c));
    return ans;
}
int SolveUsingMemo(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int a = SolveUsingMemo(n - x, x, y, z, dp) + 1;
    int b = SolveUsingMemo(n - y, x, y, z, dp) + 1;
    int c = SolveUsingMemo(n - z, x, y, z, dp) + 1;

    int ans = max(a, max(b, c));
    dp[n] = ans;
    return dp[n];
}
int SolveUsingTabu(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0 && dp[i - x] != -1)
        {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0 && dp[i - y] != -1)
        {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0 && dp[i - z] != -1)
        {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    if (dp[n] < 0)
    {
        return 0;
    }

    return dp[n];
}
int main()
{
    int n;
    cin >> n;

    int x, y, z;
    cin >> x >> y >> z;

    int ans = SolveUsingRec(n, x, y, z);
    if (ans < 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    vector<int> dp(n + 1, -1);
    int ans1 = SolveUsingMemo(n, x, y, z, dp);
    if (ans1 < 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans1 << endl;
    }

    cout << SolveUsingTabu(n, x, y, z) << endl;

    return 0;
}