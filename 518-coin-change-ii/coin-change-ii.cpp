class Solution {
public:
const int MOD = 1e9+7;
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<long long>>dp((n+1),vector<long long>(amount+1,0)); 
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int j=0;j<=amount;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j] % MOD;
                } 
                else{
                    dp[i][j]=dp[i-1][j];
                }

            }
        }
        return dp[n][amount];

    }
};