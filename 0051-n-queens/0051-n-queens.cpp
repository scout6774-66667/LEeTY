class Solution {
public:

    // Check whether we can place a queen at (row, col)
    bool isSafe(vector<string>& board, int row, int col, int n) {

        // 1. Check the same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // 2. Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }

            i--;
            j--;
        }

        // 3. Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }

            i--;
            j++;
        }

        return true;
    }


    void backtrack(vector<string>& board,
                   int row,
                   int n,
                   vector<vector<string>>& ans) {

        // All rows are filled
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column in this row
        for (int col = 0; col < n; col++) {

            // Check whether this position is safe
            if (!isSafe(board, row, col, n)) {
                continue;
            }

            // Choose
            board[row][col] = 'Q';

            // Explore
            backtrack(board, row + 1, n, ans);

            // Undo / Backtrack
            board[row][col] = '.';
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        // Create empty board
        vector<string> board(n, string(n, '.'));

        // Start from row 0
        backtrack(board, 0, n, ans);

        return ans;
    }
};