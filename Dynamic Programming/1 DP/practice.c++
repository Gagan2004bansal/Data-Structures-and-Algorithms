// Find Longest Common Subsequence in a string
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int lcs(string s1, string s2)
{
    // vector hmesha small length vale string ka bnega
    vector<int> dp(s1.length() + 1, 0);

    for (int i = 1; i <= s2.length(); i++)
    {
        int prev = 0;
        for (int j = 1; j <= s1.length(); j++)
        {
            int temp = dp[j];
            if (s1[j - 1] == s2[i - 1])
            {
                dp[j] = prev + 1;
            }
            else
            {
                dp[j] = max(dp[j - 1], dp[j]);
            }
            prev = temp;
        }
    }
    return dp[s1.length()];
}
int logestCommonSubsequence(string text1, string text2)
{
    if (text1.length() < text2.length())
    {
        return lcs(text1, text2);
    }

    return lcs(text2, text1);
}
int main()
{
    string text1, text2;
    cout << "Enter String 1 : ";
    cin >> text1;

    cout << "Enter String 2 : ";
    cin >> text2;

    int ans = logestCommonSubsequence(text1, text2);

    cout << ans << endl;

    return 0;
}