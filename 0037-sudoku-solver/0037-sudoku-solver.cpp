class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {

        // Check row and column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num)
                return false;

            if (board[i][col] == num)
                return false;
        }

        // Find 3x3 box
        int r = (row / 3) * 3;
        int c = (col / 3) * 3;

        // Check box
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }


    bool solve(vector<vector<char>>& board) {

        // Find empty cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    // Try 1 to 9
                    for (char num = '1'; num <= '9'; num++) {

                        if (isSafe(board, row, col, num)) {

                            // Put number
                            board[row][col] = num;

                            // Solve remaining cells
                            if (solve(board))
                                return true;

                            // Wrong choice, remove it
                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};