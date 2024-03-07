#include <iostream>
#include <vector>
using namespace std;
bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int painterCount = 1;
    int pairSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pairSum + arr[i] <= mid)
        {
            pairSum += arr[i];
        }
        else
        {
            painterCount++;
            if (painterCount > m || arr[i] > mid)
            {
                return false;
            }
            pairSum = arr[i];
        }
    }

    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{

    int s = 0;
    int sum = 0;
    int n = boards.size();
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
    }

    int e = sum;
    int mid = s + (e - s) / 2;

    int ans = 0;
    while (s <= e)
    {
        if (isPossible(boards, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int m;
    cin >> m;
    cout << findLargestMinDistance(arr, m) << endl;
    return 0;
}