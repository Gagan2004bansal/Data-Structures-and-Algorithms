// Minimum product subset of an array
// T.C => O(N)
// S.C => O(1)
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int negative = 0;
    int zero = 0;
    int positive = 0;
    int least = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
        }
        else if (arr[i] > 0)
        {
            positive++;
        }
        else
        {
            negative++;
            least = min(least, arr[i]);
        }
    }

    if (zero > 0)
    {
        cout << 0 << endl;
        exit(0);
    }

    int product = 1;
    if (negative % 2 != 0)
    {
        for (int i = 0; i < n; i++)
        {
            product *= arr[i];
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (least != arr[i])
            {
                product *= arr[i];
            }
        }
    }
    cout << product << endl;

    return 0;
}