class Solution {
public:
    int solve(vector<int>& nums,int n,int i,vector<int>&memo){
        if(i>=n)return 0;
        if(memo[i]!=-1){
            return memo[i];
        }
        int in=nums[i]+solve(nums,n,i+2,memo);
        int ex=solve(nums,n,i+1,memo);
        return memo[i]=max(in,ex);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>memo1(n+1,-1);
        int ex=solve(nums,n-1,0,memo1);// excluding last including first
        vector<int>memo2(n+1,-1);
        int in=solve(nums,n,1,memo2);// excluding first including last
        return max(in,ex);
    } 
};