// Given a range (L - R) print the XOR between them in time complexity of O(1) and space Complexity of O(1)
#include <iostream>
using namespace std;
int main()
{
    int L, R;
    cin >> L >> R;

    int ans = 0, ans1 = 0;
    if (L % 4 == 0)
    {
        ans = L;
    }
    else if (L % 4 == 1)
    {
        ans = 1;
    }
    else if (L % 4 == 2)
    {
        ans = (L + 1);
    }
    else if (L % 4 == 3)
    {
        ans = 0;
    }

    if (R % 4 == 0)
    {
        ans1 = R;
    }
    else if (R % 4 == 1)
    {
        ans1 = 1;
    }
    else if (R % 4 == 2)
    {
        ans1 = (R + 1);
    }
    else if (R % 4 == 3)
    {
        ans1 = 0;
    }

    cout << (ans ^ ans1);
    cout << endl;
    return 0;
}
