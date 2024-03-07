#include <iostream>
#include <vector>
using namespace std;
// vector<string> ans;
bool isSafe(vector<string> chess, int row, int col, int n)
{
    // column check krega
    for (int i = 0; i < col; i++)
    {
        if (chess[row][i] == 'Q')
        {
            return false;
        }
    }
    // diagonal check
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] == 'Q')
        {
            return false;
        }
    }

    // anti - diagonal check
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (chess[i][j] == 'Q ')
        {
            return false;
        }
    }

    return true;
}
void Solve(vector<string> &chess, int col, int n, int &count)
{
    if (col >= n)
    {
        count++;
        // return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(chess, row, col, n))
        {
            chess[row][col] = 'Q';
            Solve(chess, col + 1, n, count);
            chess[row][col] = '.';
        }
    }
}
int main()
{
    int n;
    cin >> n;

    vector<string> chess;
    for (int i = 0; i < n; i++)
    {
        string temp;
        for (int j = 0; j < n; j++)
        {
            temp += '.';
        }
        chess.push_back(temp);
    }

    int count = 0;
    Solve(chess, 0, n, count);

    cout << count << endl;

    return 0;
}