#include <iostream>
using namespace std;
int main()
{
    int left;
    cin >> left;

    int right;
    cin >> right;

    while (right > left)
    {
        right = right & (right - 1);
    }

    cout << right << endl;

    return 0;
}