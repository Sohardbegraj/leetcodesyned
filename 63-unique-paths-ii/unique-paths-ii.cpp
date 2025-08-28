class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int m,int n,vector<vector<int>>&dp){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }

                if(j==0 && i==0){
                    dp[i][j]=1;
                    continue;
                }
                int up=0; 
                int left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=left+up;
            }
        }
        return dp[m - 1][n - 1];
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n =obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans= solve(obstacleGrid,m,n,dp);
        return ans;
    }
};