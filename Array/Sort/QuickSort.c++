#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            cout << arr[i] << " " << arr[j] << endl;
            swap(arr[i], arr[j]); // ye tab tab sort kr rha h jab jab isse chota element mil rha hh pivot se
            cout << arr[i] << " " << arr[j] << endl;
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {

        int p = partition(arr, low, high);

        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
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

    int low = 0, high = n - 1;
    QuickSort(arr, low, high);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
