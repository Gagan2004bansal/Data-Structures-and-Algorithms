#include <iostream>
using namespace std;
int search(int *arr, int n, int target)
{
    int s = 0, e = n - 1;
    int mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] == arr[e] && arr[e] == arr[s])
        {
            s += 1;
            e -= 1;
            continue;
        }

        // right check
        if (arr[mid] <= arr[e])
        {
            if (arr[mid] <= target && target <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        else
        {
            if (arr[s] <= target && target <= arr[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
    }

    return -1;
}
int main()
{
    int n;
    cin >> n;

    int ele;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr[i] = ele;
    }
    int target;
    q
            cin >>
        target;
    cout << search(arr, n, target) << endl;
    return 0;
}