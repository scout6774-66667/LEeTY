class Solution {
public:
    vector<vector<string>> ans;

    bool safe(vector<string>& board, int row, int col, int n) {

        // Check column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    void solve(vector<string>& board, int row, int n) {

        // All queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column
        for (int col = 0; col < n; col++) {

            if (safe(board, row, col, n)) {

                board[row][col] = 'Q';   // Choose

                solve(board, row + 1, n); // Explore

                board[row][col] = '.';   // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(board, 0, n);

        return ans;
    }
};