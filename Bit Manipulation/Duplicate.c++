// Find a duplicate number in array in O(N) Time Complexity and O(1) space complexity
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

    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    cout << "Duplicate Element : " << ans << endl;

    return 0;
}