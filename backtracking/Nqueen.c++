// #include <iostream>
// using namespace std;

// #define N 4
// bool found = false;

// void solveNQueen(int board[N][N], int col);
// bool isSafe(int board[N][N], int row, int col);
// void printBoard(int board[N][N]);

// int main()
// {

//     // cin>>N;

//     int board[N][N] = {
//         {0, 0, 0, 0},
//         {0, 0, 0, 0},
//         {0, 0, 0, 0},
//         {0, 0, 0, 0}};

//         solveNQueen(board,0);

//     return 0;
// }

// void solveNQueen(int board[N][N], int col)
// {
//     if (col >= N)
//     {
//         // count++;
//         if (!found)
//         {
//             printBoard(board);
//             cout << endl;
//             return;
//         }
//     }

//     for (int row = 0; row < N; row++)
//     {
//         if (isSafe(board,row,col))
//         {
//             board[row][col] = 1;
//             solveNQueen(board, col + 1);
//             board[row][col] = 0;
//         }
//     }
// }

// bool isSafe(int board[N][N], int row, int col)
// {
//     for (int i = 0; i < col; i++)
//     {
//         if (board[row][i] == 1)
//         {
//             return false;
//         }
//     }

//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//     }

//     for (int i = row, j = col; i < N && j >= 0; i++, j--)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// void printBoard(int board[N][N])
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             cout << board[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

#include <iostream>
using namespace std;

#define N 4
int count = 0;
// bool found = false;

void solveNQueen(int board[N][N], int col);
bool isSafe(int board[N][N], int row, int col);
void printBoard(int board[N][N]);

int main()
{

    // cin>>N;

    int board[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    solveNQueen(board, 0);

    cout << count << endl;

    return 0;
}

void solveNQueen(int board[N][N], int col)
{
    if (col >= N)
    {
        count++;
        // if (!found)
        // {
        //     printBoard(board);
        //     cout << endl;
        //     // return;
        // }
    }

    for (int row = 0; row < N; row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            solveNQueen(board, col + 1);
            board[row][col] = 0;
        }
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}