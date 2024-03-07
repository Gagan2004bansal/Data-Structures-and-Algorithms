// Leetcode - https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/
// Firstly we find all possible sub arrays and find their XOR's

#include <iostream>
#include <vector>
using namespace std;

int XOR(vector<int> temp)
{
    int result = temp[0];

    for (int i = 1; i < temp.size(); i++)
    {
        result = result ^ temp[i];
    }

    return result;
}

void Solve(vector<int> &arr, int index, vector<int> &temp, int &sum)
{
    // Base Case
    if (temp.size() != 0)
    {
        sum += XOR(temp);
    }

    for (int i = index; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
        Solve(arr, i + 1, temp, sum);
        temp.pop_back();
    }
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

    vector<int> temp;

    int sum = 0;
    Solve(arr, 0, temp, sum);

    cout << sum << endl;
    return 0;
}