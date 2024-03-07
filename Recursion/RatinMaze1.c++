// #include <iostream>
// using namespace std;
// int row, col;
// int Solution(int i, int j)
// {
//     // Base Condition
//     if (i > row - 1 && j > col - 1)
//     {
//         return 1;
//     }

//     return Solution(i + 1, j) + Solution(i, j + 1);
// }
// int main()
// {
//     cin >> row >> col;
//     cout << Solution(0, 0) << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

int row, col;

void Solution(int i, int j, string str)
{
    // Base Condition
    if (i > row - 1 && j > col - 1)
    {
        cout << str << endl;
        return;
    }

    if (i < row)
    {
        Solution(i + 1, j, str + 'R');
    }
    if (j < col)
    {
        Solution(i, j + 1, str + 'D');
    }
}

int main()
{
    cin >> row >> col;
    Solution(0, 0, "");
    return 0;
}
