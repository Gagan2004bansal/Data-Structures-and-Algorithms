// Given a number n and i you have to check that whether the ith bit in n number is set or not
// Time Complexity => O(1)
// Space Complexity => O(1)

#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n >> i;
    if ((n & (1 << i)) != 0)
    {
        // cout << "The " << i << "th bit is set." << endl;
        int mask = ~(1 << i);
        n = n & mask;
    }
    else
    {
        // cout << "The " << i << "th bit is not set." << endl;
        int mask = (1 << i);
        n = n | mask;
    }

    cout << n << endl;
    return 0;
}