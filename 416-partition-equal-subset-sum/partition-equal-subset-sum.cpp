class Solution {
public:
    bool solve(vector<int>& nums,int sum,int n,vector<vector<int>>&memo){
        if(sum==0)return true;
        if(n==0)return false;
        if(memo[n][sum]!=-1){
            return memo[n][sum];
        }
        bool ex=solve(nums,sum,n-1,memo);
        bool in=false;
        if(nums[n-1]<=sum){
            in=solve(nums,sum-nums[n-1],n-1,memo);
        }
        return memo[n][sum]=in||ex;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int ans=sum/2;
        vector<vector<int>>memo(n+1,vector<int>(ans+1,-1));
        return solve(nums,ans,n,memo);
    }
};