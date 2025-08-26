class Solution {
public:
    const int INF = 1e9;
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INF));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        
         for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // exclude coin
                dp[i][j] = dp[i-1][j];

                // include coin (if possible)
                if (j - coins[i-1] >= 0)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i-1]]);
            }
        }
        return (dp[n][amount] >= INF ? -1 : dp[n][amount]);
    }
};