class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long zerocount=0;
        long long streak=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                streak++;
                zerocount+=streak;
            }else{
                streak=0;
            }
        }
        return zerocount;
    }
};