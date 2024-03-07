// Find all the possible ways to reach the destination
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// #include <iostream>
// using namespace std;
// int solve(int n)
// {
//     // base Case
//     if (n == 0)
//     {
//         return 1;
//     }
//     if (n == 1)
//     {
//         return 1;
//     }
//     // recursive Realtion
//     return solve(n - 1) + solve(n - 2);
// }
// int main()
// {
//     int n;
//     cin >> n;

//     cout << solve(n) << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int prev = 1;  // <-- index 0
    int prev1 = 0; // <-- index 1
    int curr;
    for (int i = 0; i < n; i++)
    {
        curr = prev1 + prev;
        prev1 = prev;
        prev = curr;
    }

    cout << prev << endl;

    return 0;
}