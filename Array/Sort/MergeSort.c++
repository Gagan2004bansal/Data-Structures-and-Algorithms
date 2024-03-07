// #include <iostream>
// #include <vector>
// using namespace std;
// void merge_arr(vector<int> &arr, int s, int e)
// {
//     int mid = s + (e - s) / 2;
//     int len1 = mid + 1 - s;
//     int len2 = e - mid;
//     int *first = new int[len1];
//     int *second = new int[len2];

//     int mainArrayIndex = s;
//     for (int i = 0; i < len1; i++)
//     {
//         first[i] = arr[mainArrayIndex++];
//     }
//     mainArrayIndex = mid + 1;
//     for (int i = 0; i < len2; i++)
//     {
//         second[i] = arr[mainArrayIndex++];
//     }

//     int index1 = 0, index2 = 0;
//     mainArrayIndex = s;

//     while (index1 < len1 && index2 < len2)
//     {
//         if (first[index1] < second[index2])
//         {
//             arr[mainArrayIndex++] = first[index1++];
//         }
//         else
//         {
//             arr[mainArrayIndex++] = second[index2++];
//         }
//     }

//     while (index1 < len1)
//     {
//         arr[mainArrayIndex++] = first[index1++];
//     }

//     while (index2 < len2)
//     {
//         arr[mainArrayIndex++] = second[index2++];
//     }

//     delete[] first;
//     delete[] second;
// }
// void mergeSort(vector<int> &arr, int s, int e)
// {
//     if (s >= e)
//     {
//         return;
//     }

//     int mid = s + (e - s) / 2;
//     mergeSort(arr, s, mid);
//     mergeSort(arr, mid + 1, e);

//     merge_arr(arr, s, e);
// }
// int main()
// {
//     int n;
//     cout << "Enter size of array : " << endl;
//     cin >> n;

//     vector<int> arr;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         arr.push_back(a);
//     }

//     int s = 0, e = n - 1;
//     mergeSort(arr, s, e);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
void MergeArray(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid + 1 - s;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}
void MergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    MergeSort(arr, s, mid);
    MergeSort(arr, mid + 1, e);

    MergeArray(arr, s, e);
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

    int s = 0;
    MergeSort(arr, s, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}