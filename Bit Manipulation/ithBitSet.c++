// Set the ith bit of a number

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, i;
//     cin >> n >> i;

//     int mask = (1 << i);
//     n = n | mask;

//     cout << n << endl;
//     return 0;
// }

// Change the ith bit of a number
#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n >> i;
    int mask = ~(1 << i);
    n = n & mask;

    cout << n << endl;
    return 0;
    return 0;
}

// How to check that the number is power of 2
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     if ((n & (n - 1)) == 0)
//     {
//         cout << "Yes" << endl;
//     }
//     else
//         cout << "No" << endl;

//     return 0;
// }

// Leetcode - 1239 // Maximum string in concatenated string with unique character
// Daily Question --> 23 January 2024

// Binary Printing
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 10; i >= 0; i--)
//     {
//         int k = n >> i;
//         if (k & 1)
//         {
//             cout << 1 << " ";
//         }
//         else
//         {
//             cout << 0 << " ";
//         }
//     }
//     cout << endl;
//     return 0;
// }