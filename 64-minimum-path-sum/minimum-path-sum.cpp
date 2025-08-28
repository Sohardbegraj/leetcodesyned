class Solution {
public:
    int solve(vector<vector<int>>& grid,int m,int n,vector<vector<int>>&memo){
        if(m==0 && n==0) return grid[0][0];

        if (m < 0 || n < 0) return 1e9; 
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        int left=grid[m][n]+solve(grid,m,n-1,memo);
        int up=grid[m][n]+solve(grid,m-1,n,memo);
        return memo[m][n]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>memo((m+1),vector<int>(n+1,-1));
        return solve(grid,m-1,n-1,memo);

    }
};