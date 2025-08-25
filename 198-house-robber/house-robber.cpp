class Solution {
public:
    int solve(vector<int>& nums,int n,int i,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int include=nums[i]+solve(nums,n,i+2,dp);
        int exclude=solve(nums,n,i+1,dp);
        return dp[i]=max(include,exclude);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=solve(nums,n,0,dp);
        return ans;

    }
};