// Binary Search on sorted 2D array
#include <iostream>
#include <vector>
using namespace std;

vector<int> findAns(vector<vector<int> > arr, int target)
{
    int row = arr.size();
    int col = arr[0].size();
    int l = 0, h = row * col - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        int tC = mid % col;
        int tR = mid / col;
        int val = arr[tR][tC];
        if (val == target)
            return {tR, tC};

        if (val < target)
            l = mid + 1;
        else
            h = mid - 1;
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int> > arr = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}};

    vector<int> ans = findAns(arr, 12);

    cout << "Element found at index: [";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i];
        else
            cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;
}

// This code is contributed by lokeshmvs21.
