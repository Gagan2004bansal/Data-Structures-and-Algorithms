// Dynamic Programming DSA MICROSOFT GOOGLE AMAZON NETFLIX ADOBE APPLE META

// Fibonacci Series using Dynamic Programming
// hme pta h nth fiboncci number pechle n-1th fibonacci series + n-2 th fiboncaci series ke sum ke equal hh
#include <iostream>
#include <vector>
using namespace std;
int fib(int n) // T.C ==> exponetial
{
    // base case
    if (n == 1 || n == 0)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

// Top Down Approach => recursion + memoisation   ==> T.C  => O(N)
int solveusingMemoisation(int n, vector<int> &dp)
{
    // base case
    if (n == 1 || n == 0)
    {
        return n;
    }

    // step 3 if ans is already exist then result ans
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Step 2   store and return using dp array
    dp[n] = solveusingMemoisation(n - 1, dp) + solveusingMemoisation(n - 2, dp);
    return dp[n];
}

// Tabulation Method  [Bottom - Up Approach]
int solveusingTabulation(int n)
{
    /// Step 1 Create a dp array
    vector<int> dp(n + 1, -1);
    // Step 2 Analyze base case and fill dp array
    dp[0] = 0;
    if (n == 0)
    {
        return dp[0];
    }
    dp[1] = 1;

    // Step 3 fill the remaining dp array
    // size = n + 1  then index ==> 0 to n and index = 0,1 is already fill
    // bache 2 -> N

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // answer return
    return dp[n];
}

int solveusingTabulationOpt(int n)
{
    int prev = 0;
    if (n == 0)
    {
        return 0;
    }
    int curr = 1;
    if (n == 1)
    {
        return 1;
    }

    int ans;
    for (int i = 2; i <= n; i++)
    {
        ans = curr + prev;
        prev = curr;
        curr = ans;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;

    // Create dp array
    vector<int> dp(n + 1, -1);
    int ans = solveusingMemoisation(n, dp);
    cout << ans << endl;

    int res = solveusingTabulation(n);
    cout << res << endl;

    int result = solveusingTabulationOpt(n);
    cout << result << endl;

    return 0;
}
