#include <bits/stdc++.h>
using namespace std;
bool isSafe(int row, int col, int n, vector<string> &board)
{
    int dupeRow = row;
    int dupeCol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = dupeRow;
    col = dupeCol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = dupeRow;
    col = dupeCol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 'Q';
            solve(col + 1, ans, board, n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> SolveQueen(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    int col = 0;
    solve(col, ans, board, n);
    return ans;
}
int main()
{
    int n;
    cout << "Enter the value of N for N-Queens: ";
    cin >> n;

    vector<vector<string>> solutions = SolveQueen(n);

    cout << "Total Solutions: " << solutions.size() << "\n";
    for (int i = 0; i < solutions.size(); i++)
    {
        cout << "Solution " << i + 1 << ":\n";
        for (string row : solutions[i])
        {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}