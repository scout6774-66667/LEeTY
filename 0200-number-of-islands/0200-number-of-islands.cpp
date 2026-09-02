class Solution {
public:

    int m, n;

    void dfs(vector<vector<char>>& grid, int r, int c) {

        // Step 1: Check invalid cells
        if (r < 0 || r >= m || c < 0 || c >= n ||
            grid[r][c] == '0') {
            return;
        }

        // Step 2: Mark current land as visited
        grid[r][c] = '0';

        // Step 3: Explore all 4 directions
        dfs(grid, r + 1, c); // down
        dfs(grid, r - 1, c); // up
        dfs(grid, r, c + 1); // right
        dfs(grid, r, c - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {

        // Step 4: Get dimensions
        m = grid.size();
        n = grid[0].size();

        int islands = 0;

        // Step 5: Scan entire grid
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                // Step 6: Found a new island
                if (grid[r][c] == '1') {

                    islands++;

                    // Step 7: Explore entire island
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};