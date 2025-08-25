class Solution {
public:
    int solve(vector<int>& nums,int n){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int curr=nums[i];
            int in=curr+prev2;
            int ex=prev;
            curr=max(in,ex);
            prev2=prev;
            prev=curr;

        }
        return prev;

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int ans=solve(nums,n);
        return ans;

    }
};