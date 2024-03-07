#include <iostream>
#include <vector>
using namespace std;
void Solve(vector<int> &arr, int &count, int sum, int target, int index)
{
    if (index == arr.size())
    {
        if (sum == target)
        {
            count++;
        }
        return;
    }

    Solve(arr, count, sum + arr[index], target, index + 1);
    Solve(arr, count, sum - arr[index], target, index + 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    int count = 0;
    int sum = 0;
    int target;
    cin >> target;

    Solve(arr, count, sum, target, 0);

    cout << "Count : " << count << endl;
    return 0;
}