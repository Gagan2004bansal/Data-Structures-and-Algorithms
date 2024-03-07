// Given a  number n , print the XOR y between (1 to n)
// In Time Complexity =>   O(1)
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;

    int ans = 0;
    if (n % 4 == 0)
    {
        cout << n << endl;
    }
    else if (n % 4 == 1)
    {
        cout << 1 << endl;
    }
    else if (n % 4 == 2)
    {
        cout << (n + 1) << endl;
    }
    else if (n % 2 == 3)
    {
        cout << 0 << endl;
    }

    return 0;
}