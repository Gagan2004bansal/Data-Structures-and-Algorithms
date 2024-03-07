#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

// As we use MOD answer should be different as we think use this code in
// Link : https://codingninjas.com/studio/problems/ninja-and-the-fence_3210208?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

int add(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}
int multi(int a, int b)
{
    return ((a % MOD) * 1LL * (b * MOD)) % MOD;
}
int SolveUsingRec(int n, int k)
{
    // Base Case
    if (n == 1)
    {
        return k;
    }

    if (n == 2)
    {
        return add(k, multi(k, k - 1));
    }

    int ans = add(multi(SolveUsingRec(n - 2, k), k - 1), multi(SolveUsingRec(n - 1, k), k - 1));
    return ans;
}
int SolveUsingMemo(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return add(k, multi(k, k - 1));
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = add(multi(SolveUsingMemo(n - 2, k, dp), k - 1), multi(SolveUsingMemo(n - 1, k, dp), k - 1));
    dp[n] = ans;

    return dp[n];
}
int SolveUsingTabu(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = add(k, multi(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(multi(dp[i - 2], k - 1), multi(dp[i - 1], k - 1));
    }

    return dp[n];
}
int SolveUsingTabuSO(int n, int k)
{
    int prev2 = k;
    int prev1 = add(k, multi(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int ans = add(multi(prev1, k - 1), multi(prev2, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    int ans = SolveUsingRec(n, k);
    cout << ans << endl;

    vector<int> dp(n + 1, -1);
    int ans1 = SolveUsingMemo(n, k, dp);
    cout << ans1 << endl;

    int ans2 = SolveUsingTabu(n, k);
    cout << ans2 << endl;

    int ans3 = SolveUsingTabuSO(n, k);
    cout << ans3 << endl;

    return 0;
}