#include <iostream>
#include <vector>
using namespace std;

const int moves[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

bool isValidMove(int N, int x, int y, vector<vector<int> > &mat)
{
    return (x >= 0 && y >= 0 && x < N && y < N && mat[x][y] == -1);
}

bool Solve(int N, int x, int y, int move, vector<vector<int> > &mat)
{
    if (move == N * N)
    {
        return true;
    }

    for (int k = 0; k < 8; ++k)
    {
        int newX = x + moves[k][0];
        int newY = y + moves[k][1];

        if (isValidMove(N, newX, newY, mat))
        {
            mat[newX][newY] = move;
            if (Solve(N, newX, newY, move + 1, mat))
            {
                return true;
            }
            mat[newX][newY] = -1;
        }
    }

    return false;
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int> > mat(n, vector<int>(n, -1));

    mat[0][0] = 0;

    if (Solve(n, 0, 0, 1, mat))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}
