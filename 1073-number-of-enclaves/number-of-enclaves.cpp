class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>>& vis,
             vector<vector<int>>& grid, int delrow[], int delcol[]) {

        vis[row][col] = true;
        int n = grid.size(), m = grid[0].size();

        for (int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                grid[nrow][ncol] == 1) {

                dfs(nrow, ncol, vis, grid, delrow, delcol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int delrow[4] = {0, 0, 1, -1};
        int delcol[4] = {1, -1, 0, 0};

        // Top and Bottom rows
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1)
                dfs(0, j, vis, grid, delrow, delcol);

            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
                dfs(n - 1, j, vis, grid, delrow, delcol);
        }

        // Left and Right columns
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1)
                dfs(i, 0, vis, grid, delrow, delcol);

            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
                dfs(i, m - 1, vis, grid, delrow, delcol);
        }

        // Count unvisited land cells
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};
