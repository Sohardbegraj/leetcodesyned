class Solution {
public:
   
    int minimumArea(vector<vector<int>> &grid, int rowi, int rowj, int coli, int colj)
    {
        int x1 = INT_MAX;   
        int y1 = INT_MAX;
        int x2 = 0; 
        int y2 = 0; 
        for(int i = rowi; i <= rowj; i++)
        {
            for(int j = coli; j <= colj; j++)
            {
                if(grid[i][j] == 1)
                {
                    x1 = min(x1, i);
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                }
            }
        }
        return x1 == INT_MAX ? 0 : (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = m * n;

       
        for(int i = 0; i < m; i++)
        {
            int R1 = minimumArea(grid, 0, i, 0, n - 1);
            for(int j = 0; j < n; j++)
                res = min(res,
                R1 + 
                minimumArea(grid, i + 1, m - 1, 0, j) +
                minimumArea(grid, i + 1, m - 1, j + 1, n - 1));
        }

        
        for(int i = 0; i < m; i++)
        {
            int R1 = minimumArea(grid, i, m - 1, 0, n - 1);
            for(int j = 0; j < n; j++)
                res = min(res,
                R1 + 
                minimumArea(grid, 0, i - 1, 0, j) +
                minimumArea(grid, 0, i - 1, j + 1, n - 1));
        }
        for(int j = 0; j < n; j++)
        {
            int R1 = minimumArea(grid, 0, m - 1, 0, j);
            for(int i = 0; i < m; i++)
                res = min(res,
                R1 + 
                minimumArea(grid, 0, i, j + 1, n - 1) +
                minimumArea(grid, i + 1, m - 1, j + 1, n - 1));
        }
        for(int j = 0; j < n; j++)
        {
            int R1 = minimumArea(grid, 0, m - 1, j, n - 1);
            for(int i = 0; i < m; i++)
                res = min(res,
                R1 + 
                minimumArea(grid, 0, i, 0, j - 1) +
                minimumArea(grid, i + 1, m - 1, 0, j - 1));
        }
        
        for(int i1 = 0; i1 < m; i1++)
        {
            for(int i2 = i1 + 1; i2 < m; i2++)
                res = min(res,
                minimumArea(grid, 0, i1, 0, n - 1) + 
                minimumArea(grid, i1 + 1, i2, 0, n - 1) +
                minimumArea(grid, i2 + 1, m - 1, 0, n - 1));
        }
        for(int j1 = 0; j1 < n; j1++)
        {
            for(int j2 = j1 + 1; j2 < n; j2++)
                res = min(res,
                minimumArea(grid, 0, m - 1, 0, j1) + 
                minimumArea(grid, 0, m - 1, j1 + 1, j2) +
                minimumArea(grid, 0, m - 1, j2 + 1, n - 1));
        }

        return res;
    }
};