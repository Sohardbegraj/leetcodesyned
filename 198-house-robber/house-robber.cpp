class Solution {
public:
    int solve(vector<int>& nums,int n,int i,vector<int>&dp){
        if(i>=n)return 0;
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int include=nums[i];
            if(i>1){
                include+=dp[i-2];
            }
            int exclude=dp[i-1];
            dp[i]=max(include,exclude);
        }
        return dp[n-1];

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n+1,-1);
        int ans=solve(nums,n,0,dp);
        return ans;

    }
};