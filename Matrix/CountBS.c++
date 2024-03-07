#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    // Declare a 2D vector to store the matrix
    vector<vector<int> > mat;

    // Input the number of rows and columns
    int row, col;
    cin >> row >> col;

    // Input the matrix elements
    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        mat.push_back(temp);
    }

    // Create a map to store row index and count of occurrences of 1 in that row
    map<int, int> mapping;
    int i = 0;
    for (auto it : mat)
    {
        for (auto j : it)
        {
            if (j == 1)
            {
                mapping[i]++;
            }
        }
        i++;
    }

    // Print the row index and count of occurrences of 1 in that row
    for (auto k : mapping)
    {
        cout << k.first << " " << k.second << endl;
    }

    return 0;
}
