// #include <iostream>
// using namespace std;
// int canPlaceCows(int *arr, int n, int cows, int distance)
// {
//     int i = 0;
//     int countCows = 1;

//     for (int j = 1; j < n; j++)
//     {
//         if (arr[j] - arr[i] >= distance)
//         {
//             countCows++;
//             i = j;
//         }
//         if (countCows == cows)
//         {
//             return 1;
//         }
//     }

//     return 0;
// }
// int maxMinDistanceOptimised(int *arr, int n, int cows)
// {
//     int s = 1, e = arr[n - 1] - arr[0], mid;
//     while (s <= e)
//     {
//         mid = (s + e) / 2;
//         if (canPlaceCows(arr, n, cows, mid))
//         {
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid - 1;
//         }
//     }
//     return e;
// }
// int maxMinDistance(int *arr, int n, int cows)
// {
//     int minDistance = 1;
//     while (canPlaceCows(arr, n, cows, minDistance))
//     {
//         minDistance++;
//     }

//     return (minDistance - 1);
// }
// int main()
// {
//     int n;
//     cin >> n;

//     int *arr = new int[n];
//     int ele;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> ele;
//         arr[i] = ele;
//     }

//     int cows;
//     cout << "enter cows : ";
//     cin >> cows;

//     cout << "Max Distance Between" << cows << " cows :  " << maxMinDistance(arr, n, cows) << endl;

//     cout << "Max Distance Between" << cows << " cows :  " << maxMinDistanceOptimised(arr, n, cows) << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
int canPlaceCows(int *stalls, int n, int cows, int distance)
{
    int i = 0;
    int countCows = 1;

    for (int j = 1; j < n; j++)
    {
        if (stalls[j] - stalls[i] >= distance)
        {
            countCows++;
            i = j;
        }
        if (countCows == cows)
        {
            return 1;
        }
    }

    return 0;
}
int aggressiveCows(int *stalls, int n, int cows)
{
    int s = 1, e = stalls[n - 1] - stalls[0], mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (canPlaceCows(stalls, n, cows, mid))
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return e;
}
int main()
{
    int n;
    cout << "Enter number of stalls : ";
    cin >> n;

    int stalls[n];
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    int cows;
    cout << "Enter number of cows : ";
    cin >> cows;

    cout << "Max distance b/w " << cows << " cows : " << aggressiveCows(stalls, n, cows) << endl;

    return 0;
}