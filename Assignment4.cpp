#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<char>> board, int n, int x)
{
    cout << "Arrangement " << x++ << "\n";
    x++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isSafe_Backtracking(vector<vector<char>> &board, int r, int c, int n)
{
    for (int i = 0; i < r; i++)
    {
        if (board[i][c] == 'Q')
        {
            return false;
        }
    }
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = r, j = c; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

static int kb = 0;
void nQueen_Backtracking(vector<vector<char>> &board, int r, int n)
{
    if (r == n)
    {
        kb++;
        printBoard(board, n, kb);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe_Backtracking(board, r, i, n))
        {
            board[r][i] = 'Q';
            nQueen_Backtracking(board, r + 1, n);
            board[r][i] = '-';
        }
    }
}

static int kbb = 0;
void nQueen_BranchAndBound(vector<vector<char>> &board, int col, int n, vector<bool> &leftrow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal)
{
    if (col == n)
    {
        kbb++;
        printBoard(board, n, kbb);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            nQueen_BranchAndBound(board, col + 1, n, leftrow, upperDiagonal, lowerDiagonal);
            board[row][col] = '-';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    cout << "Bactracking: \n\n";
    nQueen_Backtracking(board, 0, n);
    vector<bool> rows(n, false);
    vector<bool> left_digonals(2 * n - 1, false);
    vector<bool> Right_digonals(2 * n - 1, false);
    cout << "Branch and Bound: \n\n";
    nQueen_BranchAndBound(board, 0, n, rows, left_digonals, Right_digonals);
    return 0;
}