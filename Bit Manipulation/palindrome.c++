#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = arr[i] ^ arr[i + 1];
    }

    if (ans == 0 || ans == 1)
    {
        cout << "Palindrome hh" << endl;
    }
    else
    {
        cout << "Palindrome nhi hh" << endl;
    }

    return 0;
}