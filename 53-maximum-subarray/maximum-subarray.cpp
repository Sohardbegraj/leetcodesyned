class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mini=INT_MIN;
        if (n==1){
            return nums[0];
        }
        int neg=INT_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg=max(nums[i],neg);
                cout<<neg;
            }
            if(sum+nums[i] >=0){
                sum+=nums[i];
                mini=max(mini,sum);
                
            }else{
                sum=0;
            }
        }
        

        return max(mini,neg);
    }

};